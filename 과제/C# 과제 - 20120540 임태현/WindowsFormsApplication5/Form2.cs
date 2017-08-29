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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            label3.TextAlign = ContentAlignment.MiddleLeft;
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            label3.TextAlign = ContentAlignment.MiddleCenter;
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            label3.TextAlign = ContentAlignment.MiddleRight;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            Font temp = new Font(label3.Font, FontStyle.Regular);
            if (checkBox1.Checked) temp = new Font(temp, temp.Style | FontStyle.Bold);
            if (checkBox2.Checked) temp = new Font(temp, temp.Style | FontStyle.Underline);
            if (checkBox3.Checked) temp = new Font(temp, temp.Style | FontStyle.Italic);
            if (checkBox4.Checked) temp = new Font(temp, temp.Style | FontStyle.Strikeout);
            label3.Font = temp;
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            Font temp = new Font(label3.Font, FontStyle.Regular);
            if (checkBox1.Checked) temp = new Font(temp, temp.Style | FontStyle.Bold);
            if (checkBox2.Checked) temp = new Font(temp, temp.Style | FontStyle.Underline);
            if (checkBox3.Checked) temp = new Font(temp, temp.Style | FontStyle.Italic);
            if (checkBox4.Checked) temp = new Font(temp, temp.Style | FontStyle.Strikeout);
            label3.Font = temp;
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {
            Font temp = new Font(label3.Font, FontStyle.Regular);
            if (checkBox1.Checked) temp = new Font(temp, temp.Style | FontStyle.Bold);
            if (checkBox2.Checked) temp = new Font(temp, temp.Style | FontStyle.Underline);
            if (checkBox3.Checked) temp = new Font(temp, temp.Style | FontStyle.Italic);
            if (checkBox4.Checked) temp = new Font(temp, temp.Style | FontStyle.Strikeout);
            label3.Font = temp;
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)
        {
            Font temp = new Font(label3.Font, FontStyle.Regular);
            if (checkBox1.Checked) temp = new Font(temp, temp.Style | FontStyle.Bold);
            if (checkBox2.Checked) temp = new Font(temp, temp.Style | FontStyle.Underline);
            if (checkBox3.Checked) temp = new Font(temp, temp.Style | FontStyle.Italic);
            if (checkBox4.Checked) temp = new Font(temp, temp.Style | FontStyle.Strikeout);
            label3.Font = temp;
        }
    }
}
