

#include "QD3D11Widget.h"

QD3D11Widget::QD3D11Widget(QWidget *parent)
{
	QWidget::setAttribute(Qt::WA_PaintOnScreen); // ����DX��Ⱦ ...
	setFocusPolicy(Qt::WheelFocus); // ������ʱ�� ...
	setMouseTracking(true); // ��������ƶ� ...

	mTimer.setInterval(0);
	QObject::connect(&mTimer, SIGNAL(timeout()), this, SLOT(Idle()));
	mTimer.start();
}

QD3D11Widget::~QD3D11Widget()
{

}

void QD3D11Widget::Idle()
{
	RenderScene();
}

void QD3D11Widget::CreateD3DApp(HWND hwnd)
{
	mD3DApp = new D3DApplication(nullptr);
	mD3DApp->InitQt(hwnd);
}

void QD3D11Widget::RenderScene()
{
	mD3DApp->RenderQt();
}