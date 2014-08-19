//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Application->OnMessage = gHandler.messageHandler;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonInitClick(TObject *Sender)
{
	gHandler.produceOneFrame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
	gHandler.updateForm();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	Resolution sResolution;
	sResolution.setWidth(Form1->ClientWidth);
	sResolution.setHeight(Form1->ClientHeight);
	gHandler.initialize(sResolution, 1, Form1->Canvas);
	gHandler.formToUpdate = Form1;
}
//---------------------------------------------------------------------------

