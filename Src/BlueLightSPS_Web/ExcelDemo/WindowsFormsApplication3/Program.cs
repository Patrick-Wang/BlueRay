using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Reflection;

namespace WindowsFormsApplication3
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //Microsoft.Office.Interop.Excel.Application app = new Microsoft.Office.Interop.Excel.Application();
            //Workbook book = app.Workbooks.Add("E:\\12.xls");
            //Sheets shs = book.Sheets;

            //for(int i = 0; i < shs.Count; ++i){
            //    _Worksheet _wsh = (_Worksheet)shs.get_Item(i + 1);
            //    Range test = (Range)_wsh.Cells[3, 3];
            //    String val = test.Value;
            //    test.Value = val;
            //    int k = 0;
            //}
            VBARunner.VBAExcel.Start();

            VBARunner.Cell[] cells = {
                new VBARunner.Cell(),
                new VBARunner.Cell(),
                new VBARunner.Cell(),
                new VBARunner.Cell(),
                new VBARunner.Cell(),
                new VBARunner.Cell()
            };

            cells[0].sheet = 0;
            cells[0].row = 2;
            cells[0].col = 2;

            cells[1].sheet = 1;
            cells[1].row = 2;
            cells[1].col = 2;

            cells[2].sheet = 2;
            cells[2].row = 2;
            cells[2].col = 2;

            cells[3].sheet = 3;
            cells[3].row = 2;
            cells[3].col = 2;

            VBARunner.VBAExcel.RunBarcodeVBA("E:\\code\\BlueRay\\Documentation\\20.xls", cells);

            VBARunner.VBAExcel.Stop();
            System.Windows.Forms.Application.EnableVisualStyles();
            System.Windows.Forms.Application.SetCompatibleTextRenderingDefault(false);
            System.Windows.Forms.Application.Run(new Form1());
        }
    }
}
