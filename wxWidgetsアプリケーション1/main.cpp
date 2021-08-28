#include <wx/wx.h>
#include "test.h"

//メインアプリケーションクラス:wxAppの継承，OnInitのオーバーライド
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

//内部でwxAppの代わりにMyAppが呼ばれるように設定する
wxIMPLEMENT_APP(MyApp);

//メインフレームクラス:精製したMyFrame1の継承，prime_checkのオーバーライド
class MyFrame : public MyFrame1
{
public:
    //コンストラクタ・デコンストラクタはMyFrame1と全く同じにする
    using MyFrame1::MyFrame1;

private:
    //イベントに設定したprime_checkのオーバーライド
    //m_spinCtrl1の数値を取得し，素数かどうかを判別
    void prime_check(wxCommandEvent& event)
    {
        int x = this->m_spinCtrl1->GetValue();
        bool is_prime = true;
        wxString msg;
        msg.Clear();
        for (int i = x - 1; i > 1; --i)
        {
            if (!(x % i))//割り切れた
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            msg.Printf("%d is prime number!", x);
        }
        else
        {
            msg.Printf("%d is not prime number.", x);
        }

        //簡単なメッセージボックスを出す関数
        wxMessageBox(msg);

    };
};

//wxWidgetsにおける実質的なmain関数
//基本的にメインフレームをつくり，表示するだけ
bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(NULL);
    frame->Show(true);
    return true;
}