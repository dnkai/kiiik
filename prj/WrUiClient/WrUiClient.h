// ���档��WRClient�������ͨ�ţ���չʾWRClient�յ��ķ���

#ifndef WRUICLIENT_H
#define WRUICLIENT_H

#include <QMainWindow>
#include <QDialog>
#include <QProcess>
#include "ui_wruiclient.h"
#include "ui_LoginDlg.h"
#include "ui_UpdateDlg.h"
#include "WRClient.h"
#include "substblmodel.h"
#include "SymListModel.h"

class BaseDlg : public QDialog {
	Q_OBJECT

protected:
	BaseDlg(QWidget *parent = 0);
	virtual ~BaseDlg();

	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *);

	
	QPoint mousePoint;              //����϶��Զ��������ʱ������
	bool mousePressed;              //����Ƿ���
};

class WrLoginDlg : public BaseDlg, public Ui::LoginDlg
{
	Q_OBJECT

public:
	WrLoginDlg(WRClient *wr_client, QWidget *parent = 0);

private slots:
	// ��Ӧbutton�ȿؼ����¼�
	void onLogin();
	// ��ϵ����
	void onAuthor();
	// ��Ӧ����������
	void SlotLogin(const QString &);
	
private:
	WRClient *wr_client_;
};

class UpdateDlg : public BaseDlg, public Ui::UpdateDlg
{
	Q_OBJECT

public:
	UpdateDlg(const QString &, QWidget *parent = 0);

private slots:
	void on_ok_btn_clicked();
	void on_cancel_btn_clicked();
};

class WrUiClient : public QMainWindow, public Ui::MainWindow
{
	Q_OBJECT

public:
	WrUiClient(WRClient *wr_client, QWidget *parent = 0);
	virtual ~WrUiClient();

protected:
	bool eventFilter(QObject *obj, QEvent *event);
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *);

private:
	void createSymLstVew();
	void createSubTblVew();
	void connectSignalSlot();

	QPoint mousePoint;
	bool mousePressed;
	bool max;
	QRect location;

	SymListModel *sym_mdl_;
	SubsTblModel *sub_mdl_;

	WRClient *wr_client_;
	CSymbol *syms_;//��Լ�б�
	int syms_num_;//��Լ����

	QProcess pro_;

private slots: 
	// ��Ӧbutton�ȿؼ����¼�
	void onTestWrite();
	void onSub();
	void onUnsub();
	void onQuote(int = 0);
	void on_btnMenu_Close_clicked();
	void on_btnMenu_Max_clicked();
	void on_btnMenu_Min_clicked();
	void on_btnMenu_clicked();

	// ��Ӧ����������
	void SlotSymbols(CSymbol *, int);
	void SlotQuote(const CQuotation *);
	void SlotNetErr(const QString &);
};

#endif // WRUICLIENT_H
