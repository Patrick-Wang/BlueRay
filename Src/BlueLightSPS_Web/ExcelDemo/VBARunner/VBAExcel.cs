using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Microsoft.Office.Core;
using Microsoft.Office.Interop.Excel;
using System.IO;
namespace VBARunner
{
    public class VBAExcel
    {
        static Microsoft.Office.Interop.Excel.Application app;
  
        public static void Start() {
            if (null == app) {
                app = new Microsoft.Office.Interop.Excel.Application();
            }
        }

        public static void RunBarcodeVBA(String filePath, Cell[] cells) {
            Workbook book = app.Workbooks.Open(filePath);
            Sheets shs = book.Sheets;

            for (int i = 0; i < cells.Length; ++i)
            {
                _Worksheet _wsh = (_Worksheet)shs.get_Item(cells[i].sheet + 1);
                Range cell = (Range)_wsh.Cells[(cells[i].row + 1), (cells[i].col + 1)];
                Object val = cell.Value;
                cell.Value = val;
            }

            book.Save();
            book.Close();
        }

        public static void Stop()
        {
            if (null != app)
            {
                app.Quit();

                //释放掉多余的excel进程
                System.Runtime.InteropServices.Marshal.ReleaseComObject(app);
                app = null;
            }
        }
    }
}
