#ifndef SYMLISTMODEL_H
#define SYMLISTMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include <QMap>
#include "WRStruct.h"
#include "WRClient.h"

using namespace kiiik;

class SymListModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	SymListModel(WRClient *wr_client, QObject *parent);
	~SymListModel();

	// ���º�Լ�б�  // �Ѿ����ĵļ������ͣ�ˢ�²�Ӱ�������ط�����ʾ���� --- ��ͦ
	void SetSymVec(CSymbol *, int);

	int rowCount(const QModelIndex&) const;
	int columnCount(const QModelIndex &parent /* = QModelIndex() */)const;
	QVariant data(const QModelIndex &index, int role /* = Qt::DisplayRole */)const;
	QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole)const;
	//����ĳһ��Ϊ��ѡ��ɫ���滭��QCheckBox
	Qt::ItemFlags flags(const QModelIndex &index) const;
	//���ݽ���ѡ��QCheckbox���޸�Model�е�����
	bool setData(const QModelIndex &index, const QVariant &value, int role);

	// ����/�˶�������Ҫ�޸�sym_list_��check
	void ChangeState(Qt::CheckState);

	struct SymCheck {
		CSymbol sym;
		Qt::CheckState check;//�򹳣������Ѿ�����
		SymCheck() :check(Qt::Unchecked){}
		SymCheck(CSymbol &s, Qt::CheckState c) :sym(s), check(c){}
	};
private:
	QVector<SymCheck> sym_list_;

	WRClient *wr_client_;

	//virtual void sort(int, Qt::SortOrder);

private slots:
	void SlotRowClicked(const QModelIndex &);
	

signals:
	void SignalRmSym(const CSymbol &);
};

#endif // SYMLISTMODEL_H
