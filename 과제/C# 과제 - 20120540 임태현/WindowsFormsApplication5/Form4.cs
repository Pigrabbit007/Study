using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication5
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox2.Text = DecConvert(2, textBox1.Text);
            textBox3.Text = DecConvert(8, textBox1.Text);
            textBox4.Text = DecConvert(16, textBox1.Text);
        }
        private string DecConvert(int type, string a)
        {
            int r, N;
            string tmp_reverse = "";
            string tmp = "";
            string Hex = "0123456789ABCDEF";

            N = int.Parse(a);

            while(N>=type)
            {
                r = N % type;
                tmp += Hex.Substring(r, 1);
                N /= type;
            }
            
            tmp += Hex.Substring(N, 1);

            for (int i = 0; i < tmp.Length; i++)
            {
                tmp_reverse += tmp.Substring(tmp.Length - 1 - i, 1);
            } 
            
            return (tmp_reverse);
        }
    }
}
