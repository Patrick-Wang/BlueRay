#pragma once
#include <vector>
#include "CApplication.h"
#include "CRange.h"
#include "CWorkbook.h"
#include "CWorksheet.h"
#include "CWorkbooks.h"
#include "CWorksheets.h"
#include <memory>
#include "JsonFactory.h"
#include "JsonParser.h"
#include "JsonObjects.h"
#include "JsonType.h"
enum PcjhColumn {
	id,
	hth, // ��ͬ��"
	khmc, // �ͻ�����"
	ggxh, // ����ͺ�"
	cg,//�Ÿ�
	sl, // ����"
	zc, // ���"
	dfr, // ������"
	zdqdy, // �ƶ�����ѹ"
	yylgg, // ҷ���ֹ��"
	jf, // ����"
	bpqxh, // ��Ƶ���ͺ�"
	bmqxh, // �������ͺ�"
	dlcd, // ���³���"
	zxcd, // բ�߳���"
	mpzl, // ���Ƶ�����"
	bz, // ��ע"
	ddrq, // ��������"
	zjdy, // ������ѹ
	zjys, // ������ɫ
	zdqxh, // �ƶ����ͺ�
	zyz, // ��/����
	bzxdtgg, // ��װ��/���й��
	gh, // ����
	zzs, // ������
	khqy, // �ͻ�����
	yxj, // ���ȼ�"
	scrq, // ��������"
	jhshyw, // �ƻ����-ҵ��"
	jhshjh, // �ƻ����-�ƻ�"
	bzrq, // ��װ����"
	bzshyw, // ��װ���-ҵ��"
	bzshjh, // ��װ���-�ƻ�"
	fhrq, // ��������"
	tcbh, // Ͷ�����"
	ccbh, // �������"
	end
};

class ExcelVBAService
{
public:
	ExcelVBAService();
	~ExcelVBAService();
	bool Start();
	void Stop();
	//void updateCell(CString& path,
	//	std::vector<int>& shts,
	//	std::vector<int>& rows,
	//	std::vector<int>& cols);
	void UpdateTemplate(std::shared_ptr<Json::JsonObject> jsonTemplate);
private:
	void UpdateSheet(Json::JsonArray& row, Json::JsonObject& tempalteMap);
	void UpdateCells(Json::JsonArray& cells, Json::json_string& value);
	void LoadExcel(LPCTSTR lpPath);
	void ReleaseExcel(LPCTSTR lpPath);
	PcjhColumn getCol(Json::json_string& strCol);
private:
	bool m_bStarted;
	CApplication ExcelApp;
	CWorkbooks books;
	CWorkbook book;
	CWorksheets sheets;
	CWorksheet sheet;
	CRange range;
};

