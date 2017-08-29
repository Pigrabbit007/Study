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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox3.Text = (float.Parse(textBox1.Text) * float.Parse(textBox2.Text)).ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox3.Text = (float.Parse(textBox1.Text) / float.Parse(textBox2.Text)).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox3.Text = (float.Parse(textBox1.Text) - float.Parse(textBox2.Text)).ToString();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox3.Text = (float.Parse(textBox1.Text) + float.Parse(textBox2.Text)).ToString();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox3.Text = (float.Parse(textBox1.Text) % float.Parse(textBox2.Text)).ToString();
        }
    }
}
