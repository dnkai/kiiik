// ������table�����ݣ�qtableview��Ϊ�����һ����

#ifndef SUBSTBLMODEL_H
#define SUBSTBLMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QMap>
#include <QMutex>
#include "WRStruct.h"
#include "WRClient.h"

using namespace kiiik;

// ����Լӳ���size_t
inline size_t SymbolToInt(const CSymbol &symbol){
	size_t ret = 0, i = 0;
	while (symbol.m_ProductId[i] && i < 8)
	{
		ret = ret * 26 + symbol.m_ProductId[i] - 'A';
		++i;
	}
	return ret * 1000 + symbol.m_ContractDays;
}

class SubsTblModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	SubsTblModel(QObject *parent);
	~SubsTblModel();

	int rowCount(const QModelIndex&) const;
	int columnCount(const QModelIndex &parent /* = QModelIndex() */)const;
	QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */)const;
	QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole)const;

	//void SetSymVec(CSymbol *, int);
	void GetSymVec(std::vector<CSymbol> &inst_vec);

private:
	struct CQuotationLine {
		CQuotation *data;
		int line; // �����ڵڼ���
	};
	QMap<size_t, CQuotationLine> wr_data_line_;// ����Լӳ���size_t
	QList<CQuotation> wr_quote_datas_;

	virtual void sort(int, Qt::SortOrder);

private slots:
	void SlotTickRsp(const CQuotation *);//��������
	void SlotRmSym(const CSymbol &);//ȡ������ĳ��Ʒ�ֵ�����
};

#endif // SUBSTBLMODEL_H
