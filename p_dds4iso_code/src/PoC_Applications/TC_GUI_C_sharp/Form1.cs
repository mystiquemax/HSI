// MIT License
// 
// Copyright (c) 2024 Samuel Brodie, Timo Oksanen, Henri Hornburg, Daniel Ostermeier, Maksim Pavlov Technical University of Munich
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using System.Xml.Linq;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
namespace TC_GUI
{
    public partial class HSI_Taskcontroller : Form
    {
        private int tank_fill_value = 0;
        private class HSI_Backend
        {
            public HSI_Backend(HSI_Taskcontroller form_control)
            {
                this.form_control = form_control;
            }
            // Delegate simulates functionpointer
            public delegate void update_tank_fill_del(float min_fill, float curr_fill, float max_fill);
            public delegate void update_Device_t_cb_del([MarshalAs(UnmanagedType.LPStr)] string id, [MarshalAs(UnmanagedType.LPStr)] string designator,
                [MarshalAs(UnmanagedType.LPStr)] string softwareversion, [MarshalAs(UnmanagedType.LPStr)] string name,
                [MarshalAs(UnmanagedType.LPStr)] string serialnumber, [MarshalAs(UnmanagedType.LPStr)] string structurelabel,
                [MarshalAs(UnmanagedType.LPStr)] string localizationlabel);
            public delegate void update_DeviceElement_t_cb([MarshalAs(UnmanagedType.LPStr)] string name, UInt64 element_ref_name, UInt64 element_ref_element_num,
                UInt64 parent_ref_name, UInt64 parent_ref__element_num, byte connector_nr);
            public delegate void update_ControlHandlingCapabilities_t_cb(UInt64 element_ref_name, UInt64 element_ref_element_num,
                [MarshalAs(UnmanagedType.LPStr)] string handling_group, byte option_nr, [MarshalAs(UnmanagedType.LPStr)] string unit);
            public delegate void update_ControlHandlingValues_t_cb(UInt64 element_ref_name, UInt64 element_ref_element_num,
                [MarshalAs(UnmanagedType.LPStr)] string handling_feature, [MarshalAs(UnmanagedType.LPStr)] string handling_group,
                double value, [MarshalAs(UnmanagedType.LPStr)] string unit);
            public delegate double get_setpoint();
            public delegate void read_lat_lon_cb_del(UInt64 name, double lat, double lon);
            public delegate void name_disconnect_cb(UInt64 name);
            // "Alias" external function receiving functionpointer as callback from dll
            [DllImport("HSI_SPRAYER_LIB.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void TC_logic_run(
                bool isCalledFromGuiNotCmd,
                update_tank_fill_del update_tank_cb,
                update_Device_t_cb_del update_Device_t_cb,
                update_DeviceElement_t_cb update_DeviceElement_t_cb,
                update_ControlHandlingCapabilities_t_cb update_ControlHandlingCapabilities_t_cb,
                update_ControlHandlingValues_t_cb update_ControlHandlingValues_t_cb,
                get_setpoint get_setpoint,
                read_lat_lon_cb_del read_lat_lon_cb,
                name_disconnect_cb name_disconnect_cb);
            // "Alias" external function receiving functionpointer as callback from dll
            [DllImport("HSI_SPRAYER_LIB.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern void TC_logic_stop();
            [DllImport("HSI_SPRAYER_LIB.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern int test_start();
            [DllImport("HSI_SPRAYER_LIB.dll", CallingConvention = CallingConvention.Cdecl)]
            public static extern double test_readUpdate_app_rate();
            // Tank fill callback function
            // Note: https://stackoverflow.com/questions/7609839/accessing-a-forms-control-from-a-separate-thread
            public void cb_update_tank_fill(float min_fill, float curr_fill, float max_fill)
            {
                // needed to stop gui hanging
                this.form_control.Invoke(() => form_control.set_tank_fill_indicator((int)curr_fill));
            }
            public void cb_update_Device_t(string id, string designator, string softwareversion,
                string name, string serialnumber, string structurelabel, string localizationlabel)
            {
                // needed to stop gui hanging
                this.form_control.Invoke(() => form_control.add_to_listView_t_device(id, designator, softwareversion,
                name, serialnumber, structurelabel, localizationlabel));
            }
            public void cb_update_DeviceElement_t(string name, UInt64 element_ref_name, UInt64 element_ref_element_num,
                UInt64 parent_ref_name, UInt64 parent_ref__element_num, byte connector_nr)
            {
                // needed to stop gui hanging
                this.form_control.Invoke(() => form_control.add_to_listView_t_ddop_hierarchy(name, element_ref_name, element_ref_element_num,
                parent_ref_name, parent_ref__element_num, connector_nr));
            }
            public void cb_update_ControlHandlingCapabilities_t(UInt64 element_ref_name, UInt64 element_ref_element_num,
                string handling_group, byte option_nr, string unit)
            {
                // needed to stop gui hanging
                this.form_control.Invoke(() => form_control.add_to_listView_t_ddi_linking(element_ref_name, element_ref_element_num,
                handling_group, option_nr, unit));
            }
            public void cb_update_ControlHandlingValues_t(UInt64 element_ref_name, UInt64 element_ref_element_num,
                string handling_feature, string handling_group, double value, string unit)
            {
                // needed to stop gui hanging
                this.form_control.Invoke(() => form_control.add_to_listView_t_pd_values(element_ref_name, element_ref_element_num,
                handling_feature, handling_group, value, unit));
            }
            public double cb_get_setpoint()
            {
                return (double)this.form_control.Invoke(() => form_control.numeUpDown_setpoint.Value);
            }
            public void read_lat_lon_cb(UInt64 name, double lat, double lon)
            {
                this.form_control.Invoke(() => form_control.add_to_listView_GNSS(name, lat, lon));
            }
            public void cb_name_disconnect(UInt64 name)
            {
                this.form_control.Invoke(() => form_control.remove_name_from_all_boxes(name));
            }
            private HSI_Taskcontroller form_control;
        }
        private Thread? hsiThread;
        private HSI_Backend hsiBackendInstance;
        public HSI_Taskcontroller()
        {
            InitializeComponent();
            this.FormClosing += Form_Closing;
            hsiBackendInstance = new HSI_Backend(this);
            //HSI_Backend.test_start();
        }
        private void set_tank_fill_indicator(int percentageValue)
        {
            //tank_fill.Value = percentageValue;
        }
        private void add_to_listView_t_device(string id, string designator, string softwareversion,
                string name, string serialnumber, string structurelabel, string localizationlabel)
        {
            string[] x = [id, designator, softwareversion, name, serialnumber, structurelabel, localizationlabel];
            dataGridView_t_device.Rows.Add(x);
        }
        private void add_to_listView_t_ddop_hierarchy(string name, UInt64 element_ref_name, UInt64 element_ref_element_num,
                UInt64 parent_ref_name, UInt64 parent_ref__element_num, byte connector_nr)
        {
            string[] x = [name,
                "0x" + element_ref_name.ToString("X16"),
                element_ref_element_num.ToString(),
                "0x" + parent_ref_name.ToString("X16"),
                parent_ref__element_num.ToString(),
                connector_nr.ToString()];
            dataGridView_t_ddop_hierarchy.Rows.Add(x);
        }
        private void add_to_listView_t_ddi_linking(UInt64 element_ref_name, UInt64 element_ref_element_num,
                string handling_group, byte option_nr, string unit)
        {
            string[] x = ["0x" + element_ref_name.ToString("X16"), element_ref_element_num.ToString(), handling_group, option_nr.ToString(), unit];
            dataGridView_t_ddi_linking.Rows.Add(x);
        }
        private void add_to_listView_t_pd_values(UInt64 element_ref_name, UInt64 element_ref_element_num,
                    string handling_feature, string handling_group, double value, string unit)
        {
            string elementRefNameString = "0x" + element_ref_name.ToString("X16");
            string elementRefElementNumString = element_ref_element_num.ToString();
            // Find the row with the same element_ref_name and element_ref_element_num
            var row = dataGridView_control_values.Rows.Cast<DataGridViewRow>()
                .FirstOrDefault(r => r.Cells[0]?.Value?.ToString() == elementRefNameString
                && r.Cells[1]?.Value?.ToString() == elementRefElementNumString
                && r.Cells[2]?.Value?.ToString() == handling_feature);
            if (row == null)
            {
                // If the row doesn't exist, add a new row
                string[] x = { elementRefNameString, elementRefElementNumString, handling_feature, handling_group, value.ToString(), unit };
                dataGridView_control_values.Rows.Add(x);
            }
            else
            {
                // If the row exists, update the values
                row.Cells[3].Value = handling_group;
                row.Cells[4].Value = value.ToString();
                row.Cells[5].Value = unit;
            }
        }
        private void add_to_listView_GNSS(UInt64 name, double lat, double lon)
        {
            // Check if there is an existing row
            if (dataGridView_GNSS.Rows.Count > 0)
            {
                // Update the existing row with the updated values
                dataGridView_GNSS.Rows[0].SetValues(name.ToString("X16"), lat.ToString(), lon.ToString());
            }
            else
            {
                // Add a new row with the updated values
                string[] row = { name.ToString("X16"), lat.ToString(), lon.ToString() };
                dataGridView_GNSS.Rows.Add(row);
            }
        }
        private void remove_name_from_all_boxes(UInt64 name)
        {
            string s_name = "0x" + name.ToString("X16");
            // Check dataGridView_t_device for rows with matching name
            //in the t_device table the NAME is in a different format
            foreach (DataGridViewRow row in dataGridView_t_device.Rows)
                if (row.Cells[3].Value?.ToString() == "0x" + name.ToString("X"))
                    dataGridView_t_device.Rows.Remove(row);
            // Check dataGridView_ddop_hierarchy for rows with matching name
            foreach (DataGridViewRow row in dataGridView_t_ddop_hierarchy.Rows)
                if (row.Cells[1].Value?.ToString() == s_name)
                    dataGridView_t_ddop_hierarchy.Rows.Remove(row);
            // Check dataGridView_t_ddi_linking for rows with matching name
            foreach (DataGridViewRow row in dataGridView_t_ddi_linking.Rows)
                if (row.Cells[0].Value?.ToString() == s_name)
                    dataGridView_t_ddi_linking.Rows.Remove(row);
            // Check dataGridView_control_values for rows with matching name
            foreach (DataGridViewRow row in dataGridView_control_values.Rows)
                if (row.Cells[0].Value?.ToString() == s_name && row.Cells[2].Value?.ToString() != "setpoint")
                    dataGridView_control_values.Rows.Remove(row);
            // Check dataGridView_GNSS for rows with matching name
            foreach (DataGridViewRow row in dataGridView_GNSS.Rows)
                if (row.Cells[0].Value?.ToString() == s_name)
                    dataGridView_GNSS.Rows.Remove(row);
        }
        private void HSI_Taskcontroller_Load(object sender, EventArgs e)
        {
        }
        const bool isCalledFromGuiNotCmd = true;
        private void start_button_Click(object sender, EventArgs e)
        {
            if (hsiThread == null)
            {
                hsiThread = new Thread(() =>
                HSI_Backend.TC_logic_run(
                    true,
                    hsiBackendInstance.cb_update_tank_fill,
                    hsiBackendInstance.cb_update_Device_t,
                    hsiBackendInstance.cb_update_DeviceElement_t,
                    hsiBackendInstance.cb_update_ControlHandlingCapabilities_t,
                    hsiBackendInstance.cb_update_ControlHandlingValues_t,
                    hsiBackendInstance.cb_get_setpoint,
                    hsiBackendInstance.read_lat_lon_cb,
                    hsiBackendInstance.cb_name_disconnect)); ;
                hsiThread.Start();
            }
        }
        private void Form_Closing(object? sender, FormClosingEventArgs e)
        {
            if (hsiThread != null)
            {
                HSI_Backend.TC_logic_stop();
                hsiThread.Join();
            }
        }
        private void sprayrate_in_TextChanged(object sender, EventArgs e)
        {
        }
        private void btn_read_rate_Click(object sender, EventArgs e)
        {
            double x = HSI_Backend.test_readUpdate_app_rate();
        }
    }
}
