using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace DisplayBoard
{
    public partial class Form1 : Form
    {
        PictureBox[] masu;
        public Form1()
        {
            InitializeComponent();

            InitBoard();

            Task.Run(() => {
                TcpServer ts = new TcpServer(50010, "10.25.222.212");
                ts.Listen();
            });

            OppositeTurn("金", masu[0]);
            MyTurn("飛", masu[10]);

            ParseKifuStr("+6978KI");
        }

        private void InitBoard()
        {
            int x = 550;
            int y = 50;

            masu = new PictureBox[81];

            for (int i = 0; i < 81; i++)
            {
                masu[i] = new PictureBox();

                masu[i].Parent = this;
                masu[i].Width = 50;
                masu[i].Height = 50;
                masu[i].BorderStyle = BorderStyle.FixedSingle;

                Padding p = new System.Windows.Forms.Padding();
                p.Left = 3;
                p.Top = 8;
                p.Bottom = 5;
                masu[i].Padding = p;

                masu[i].SizeMode = PictureBoxSizeMode.StretchImage;
            }

            for (int i=0;i<9;i++)
            {
                y = 50;
                x -= 50;

                for(int j=0;j<9;j++)
                {
                    masu[i + j * 9].Location = new Point(x, y);
                    y += 50;
                }
            }
        }

        private void ParseKifuStr(string str)
        {
            string tmp_turn = str.Substring(0, 1);
            bool turn;
            if ("+" == tmp_turn)
                turn = true;
            else
                turn = false;
            string from = str.Substring(1, 2);
            string to = str.Substring(3, 2);
            string koma = str.Substring(5, 2);

            PutKoma(turn, from, to, koma);
        }

        private void PutKoma(bool turn, string from, string to, string koma)
        {
            int tmp = 0;
            int ifrom = int.Parse(from);
            tmp = (((ifrom % 10) - 1) * 9) + ((ifrom / 10) - 1);
            ifrom = tmp;
            int ito = int.Parse(to);
            tmp = (((ito % 10) - 1) * 9) + ((ito / 10) - 1);
            ito = tmp;

            string koma_display = ConvertKoma(koma);

            if (turn)
            {
                MyTurn(" ", masu[ifrom]);
                MyTurn(koma_display, masu[ito]);
            }
            else
            {
                OppositeTurn(" ", masu[ifrom]);
                OppositeTurn(koma_display, masu[ito]);
            }
        }

        private string ConvertKoma(string koma)
        {
            string koma_display = string.Empty;

            switch(koma)
            {
                case "OU":
                    koma_display = "王";
                    break;
                case "KI":
                    koma_display = "金";
                    break;
                case "GI":
                    koma_display = "銀";
                    break;
                case "KY":
                    koma_display = "香";
                    break;
                case "KE":
                    koma_display = "桂";
                    break;
                case "HI":
                    koma_display = "飛";
                    break;
                case "KA":
                    koma_display = "角";
                    break;
                case "FU":
                    koma_display = "歩";
                    break;
                case "NY":
                    koma_display = "金";
                    break;
                case "NK":
                    koma_display = "金";
                    break;
                case "NG":
                    koma_display = "金";
                    break;
                case "RY":
                    koma_display = "竜";
                    break;
                case "UM":
                    koma_display = "馬";
                    break;
            }

            return koma_display;
        }

        private void MyTurn(string s, PictureBox masu)
        {
            //描画先とするImageオブジェクトを作成する
            Bitmap canvas = new Bitmap(masu.Width, masu.Height);
            //ImageオブジェクトのGraphicsオブジェクトを作成する
            Graphics g = Graphics.FromImage(canvas);

            //座標(30, 10)に描画するため、ワールド変換を平行移動
            //g.TranslateTransform(50, 50);

            //使用するFontオブジェクトを作成
            Font fnt = new Font("HGSゴシックMメディウム", 26.0f);

            //文字列を(0, 0)に描画
            g.DrawString(s, fnt, Brushes.Black, 0, 0);

            //リソースを解放する
            fnt.Dispose();
            g.Dispose();

            //PictureBox1に表示する
            masu.Image = canvas;
        }

        private void OppositeTurn(string s, PictureBox masu)
        {
            //描画先とするImageオブジェクトを作成する
            Bitmap canvas = new Bitmap(masu.Width, masu.Height);
            //ImageオブジェクトのGraphicsオブジェクトを作成する
            Graphics g = Graphics.FromImage(canvas);

            //座標(30, 10)に描画するため、ワールド変換を平行移動
            g.TranslateTransform(50, 50);
            //ワールド変換行列を45度回転する
            g.RotateTransform(180F);

            //使用するFontオブジェクトを作成
            Font fnt = new Font("HGSゴシックMメディウム", 26.0f);

            //文字列を(0, 0)に描画
            g.DrawString(s, fnt, Brushes.Black, 0, 0);

            //リソースを解放する
            fnt.Dispose();
            g.Dispose();

            //PictureBox1に表示する
            masu.Image = canvas;
        }
    }
}

/*
+6978KI
-8384FU
+7776FU
-4152KI
+2726FU
-3334FU
+2625FU
-5142OU
+2524FU
-2288UM
+7988GI
-4233OU 
*/
