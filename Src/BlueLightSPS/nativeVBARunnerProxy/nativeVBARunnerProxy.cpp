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

JNIEXPORT void JNICALL Java_com_vbarunner_VBAExcel_runVBABarcode(JNIEnv * jvm, jobject obj, jstring path, jobjectArray cells)
{
	wchar_t* str = jstringTostring(jvm, path);
	System::String^ csPath = gcnew System::String(str);
	Log(L"str %s", str);

	jboolean jb = false;
	int count = jvm->GetArrayLength(cells);
	array<VBARunner::Cell^, 1>^ csCells = gcnew  array<VBARunner::Cell^, 1>(count);
	Log(L"count %d", count);
	for (size_t i = 0; i < count; i++)
	{
		jobject jo = jvm->GetObjectArrayElement(cells, i);

		jint* jia = jvm->GetIntArrayElements((jintArray)jo, &jb);

		csCells[i] = gcnew VBARunner::Cell();
		csCells[i]->sheet = jia[0];
		Log(L"sheet %d", csCells[i]->sheet);
		csCells[i]->row = jia[1];
		Log(L"r %d", csCells[i]->row);
		csCells[i]->col = jia[2];
		Log(L"c %d", csCells[i]->col);
	}
	
	VBARunner::VBAExcel::RunBarcodeVBA(csPath, csCells);
}