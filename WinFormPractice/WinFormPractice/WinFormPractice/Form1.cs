﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormPractice
{

    public partial class Form1 : Form
    {
        HistoryForm historyForm;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Console.WriteLine("Hello World");
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            ttBtn.Text = false.ToString();
            historyForm = new HistoryForm();
            historyForm.Show();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            historyForm.richTextBox1.AppendText("hehehe\r\n");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (historyForm != null)
            {
                historyForm.richTextBox1.Text = "";
            }
        }
    }
}
