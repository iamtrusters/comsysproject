#pragma once

#include "wx/wx.h"
#include "wx/slider.h"
#include "wx/stattext.h"
#include "wx/imagpng.h"
#include "wx/image.h"
#include <wx/mediactrl.h>

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
public:

	//Declare button pointer
	wxButton* m_btn1 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxButton* m_btn3 = nullptr;
	wxButton* m_btn4 = nullptr;
	//Declare Textbox pointer 
	wxTextCtrl* m_txt1 = nullptr;
	wxTextCtrl* m_txt2 = nullptr;
	//Declare ListBox Pointer
	wxListBox* m_list1 = nullptr;
	wxListBox* m_list2 = nullptr;
	//Declare slider pointer
	wxSlider* m_slider = nullptr;
	//Declare Static Text
	wxStaticText* m_text1 = nullptr;
	wxStaticText* m_text2 = nullptr;
	wxStaticText* m_text3 = nullptr;
	//Declare the image box
	//Use PNG image format, BMP is by default, we need to modify it
	wxPNGHandler* png = new wxPNGHandler;
	wxJPEGHandler* jpeg = new wxJPEGHandler;
	//Declare image
	wxStaticBitmap* image1 = nullptr;
	wxStaticBitmap* image2 = nullptr;
	wxBitmap* bitmap1 = nullptr;
	wxBitmap* bitmap2 = nullptr;
	//wxMediaCtrl* m_video1 = nullptr;
	//wxMediaCtrl* m_video2 = nullptr;






	void OnButtonCliked1(wxCommandEvent& evt);
	void OnButtonCliked2(wxCommandEvent& evt);
	//scrollbar event
	void ScrollBar1(wxScrollEvent& event);

	
	


	//a table of event
	wxDECLARE_EVENT_TABLE();
};

