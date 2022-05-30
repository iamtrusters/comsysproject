#include "cMain.h"
#include <string.h>

using namespace std;


//Event table

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonCliked1)
EVT_BUTTON(10002, OnButtonCliked2)
EVT_COMMAND_SCROLL(10003, ScrollBar1)
wxEND_EVENT_TABLE()
//
string a = "                                                                                                    ";
cMain::cMain() : wxFrame(nullptr, wxID_ANY, a+"Static background remover", wxPoint(30, 30), wxSize(800, 600), wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
	
	//Definition for button
	m_btn1 = new wxButton(this, 10001, "Open Video", wxPoint(40, 30), wxSize(150, 35));
	m_btn2 = new wxButton(this, 10002, "New Bkgnd", wxPoint(40, 100), wxSize(150, 35));
	m_btn3 = new wxButton(this, wxID_ANY, "20", wxPoint(130, 485), wxSize(50, 50));
	m_btn4 = new wxButton(this, wxID_ANY, "Export", wxPoint(600, 485), wxSize(150, 50));

	//Text boxes
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(220, 30), wxSize(500, 35), wxALIGN_CENTRE_HORIZONTAL);
	m_txt2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(220, 100), wxSize(500, 35), wxALIGN_CENTRE_HORIZONTAL);

	//Slider Bar
	m_slider = new wxSlider(this, 10003, 20,0,100,wxPoint(200, 500), wxSize(400,20));

	//Texts: Original, Preview, Threshold
	m_text1 = new wxStaticText(this, wxID_ANY, "Tolerance", wxPoint(50, 500), wxSize(50, 50));
	m_text2 = new wxStaticText(this, wxID_ANY, "Original Video", wxPoint(150, 175), wxSize(100, 50));
	m_text3 = new wxStaticText(this, wxID_ANY, "Preview", wxPoint(545, 175), wxSize(100, 50));
	//Change the font size, apply for all
	wxFont font = m_text1->GetFont();
	font.SetPointSize(font.GetPointSize() + 3);
	m_text1->SetFont(font);
	m_btn1->SetFont(font);
	m_btn2->SetFont(font);
	m_btn3->SetFont(font);
	m_btn4->SetFont(font);
	m_txt1->SetFont(font);
	m_txt2->SetFont(font);
	//Change the font privately for Original and Preview
	font.SetPointSize(font.GetPointSize() + 2);
	m_text2->SetFont(font);
	m_text3->SetFont(font);

	//Add image handler
	wxImage::AddHandler(png);
	wxImage::AddHandler(jpeg);

	//Original Image
	bitmap1 = new wxBitmap("huy.png", wxBITMAP_TYPE_PNG);    
	wxImage img1 = bitmap1->ConvertToImage();    //create image from bitmap
	img1.Rescale(368, 207); //rescale the image
	wxBitmap NewBitmap(img1);    //convert back to bitmap
	image1 = new wxStaticBitmap(this, wxID_ANY,img1, wxPoint(20, 200), wxSize(368, 207));

	//Preview Image
	bitmap2 = new wxBitmap("huy.png", wxBITMAP_TYPE_PNG);   //create a bitmap
	wxImage img2 = bitmap2->ConvertToImage();   //create an image from the bitmap
	img2.Rescale(368, 207);   //rescale the image
	wxBitmap newBitmap(img2);
	image2 = new wxStaticBitmap(this, wxID_ANY, img2, wxPoint(400, 200), wxSize(368, 207));
	

	//add video if we change our mind
	//m_video1 = new wxMediaCtrl(this, wxID_ANY, "video.mp4", wxPoint(40, 200), wxSize(300, 240), wxMC_NO_AUTORESIZE);
	//m_video2 = new wxMediaCtrl(this, wxID_ANY, "Knight.mp4", wxPoint(450, 200), wxSize(300, 240), wxMC_NO_AUTORESIZE);
	//m_video1->ShowPlayerControls();
	//m_video2->ShowPlayerControls();
}

cMain::~cMain()	
{

}

void cMain::OnButtonCliked1(wxCommandEvent& evt)
{
	m_list1->AppendString(m_txt1->GetValue());
	evt.Skip();
}


void cMain::OnButtonCliked2(wxCommandEvent& evt)
{
	m_list2->AppendString(m_txt2->GetValue());
	evt.Skip();
}

void cMain::ScrollBar1(wxScrollEvent& evt)
{
	int a = m_slider->GetValue();
	std::string b = std::to_string(a);
	m_btn3->SetLabel(b);
	evt.Skip();
}




//parent window takes responsibility to distribute events