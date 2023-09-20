using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;

namespace WindowsFormLaba3Stankin
{
    public partial class Form1 : Form
    {
        private SqlConnection sql = null;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            sql = new SqlConnection(ConfigurationManager.ConnectionStrings["TestBd"].ConnectionString);
            sql.Open();
            
            if(sql.State==ConnectionState.Open)
            {
                MessageBox.Show("Подключение установленио!");
            }
        }
    }
}
