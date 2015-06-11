// nativeVBARunnerProxy.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "com_vbarunner_VBAExcel.h"
#include <malloc.h>
#include "LogFile.h"



wchar_t* jstringTostring(JNIEnv* env, jstring jstr)
{
	wchar_t* rtn = NULL;
	jclass clsstring = env->FindClass("java/lang/String");
	jstring strencode = env->NewStringUTF("utf-16le");
	jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)env->CallObjectMethod(jstr, mid, strencode);
	jsize alen = env->GetArrayLength(barr);
	jbyte* ba = env->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0)
	{
		rtn = (wchar_t*)malloc(alen + 2);
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
		rtn[alen + 1] = 0;
	}
	env->ReleaseByteArrayElements(barr, ba, 0);
	return rtn;
}


JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_start(JNIEnv * jvm, jobject obj)
{
	VBARunner::VBAExcel::Start();
}

JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_stop(JNIEnv * jvm, jobject obj)
{
	VBARunner::VBAExcel::Stop();
}

JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_runVBABarcode(JNIEnv * jvm, jobject obj, jstring path, jintArray sheets, jintArray rows, jintArray cols)
{
	wchar_t* str = jstringTostring(jvm, path);
	System::String^ csPath = gcnew System::String(str);
	Log(L"str %s", str);

	jboolean jb = false;
	int count = jvm->GetArrayLength(sheets);
	array<VBARunner::Cell^, 1>^ csCells = gcnew  array<VBARunner::Cell^, 1>(count);
	Log(L"count %d", count);
	jint* jias = jvm->GetIntArrayElements(sheets, &jb);
	jint* jiar = jvm->GetIntArrayElements(rows, &jb);
	jint* jiac = jvm->GetIntArrayElements(cols, &jb);

	for (size_t i = 0; i < count; i++)
	{

		
		csCells[i] = gcnew VBARunner::Cell();
		csCells[i]->sheet = jias[i];
		Log(L"sheet %d", csCells[i]->sheet);
		csCells[i]->row = jiar[i];
		Log(L"r %d", csCells[i]->row);
		csCells[i]->col = jiac[i];
		Log(L"c %d", csCells[i]->col);
	}
	
	VBARunner::VBAExcel::RunBarcodeVBA(csPath, csCells);
}