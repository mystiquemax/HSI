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

﻿namespace TC_GUI
{
    partial class HSI_Taskcontroller
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            GroupBox groupBox3;
            GroupBox groupBox2;
            GroupBox groupBox1;
            GroupBox groupBox5;
            dataGridView_control_values = new DataGridView();
            dataGridViewTextBoxColumn10 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn11 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn12 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn13 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn14 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn15 = new DataGridViewTextBoxColumn();
            dataGridView_t_ddi_linking = new DataGridView();
            dataGridViewTextBoxColumn2 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn3 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn6 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn7 = new DataGridViewTextBoxColumn();
            dataGridViewTextBoxColumn8 = new DataGridViewTextBoxColumn();
            dataGridView_t_device = new DataGridView();
            Column_id = new DataGridViewTextBoxColumn();
            Column_designator = new DataGridViewTextBoxColumn();
            Column_softwareversion = new DataGridViewTextBoxColumn();
            Column_NAME = new DataGridViewTextBoxColumn();
            Column_serialnumber = new DataGridViewTextBoxColumn();
            Column_structurelabel = new DataGridViewTextBoxColumn();
            Column_localizationlabel = new DataGridViewTextBoxColumn();
            dataGridView_t_ddop_hierarchy = new DataGridView();
            dataGridViewTextBoxColumn4 = new DataGridViewTextBoxColumn();
            Column_my_element_ref_name = new DataGridViewTextBoxColumn();
            Column_element_ref_element_num = new DataGridViewTextBoxColumn();
            Column_parent_ref_name = new DataGridViewTextBoxColumn();
            Column_parent_ref__element_num = new DataGridViewTextBoxColumn();
            Column_connector_nr = new DataGridViewTextBoxColumn();
            startButton = new Button();
            numeUpDown_setpoint = new NumericUpDown();
            label1 = new Label();
            dataGridView_GNSS = new DataGridView();
            dataGridViewTextBoxColumn5 = new DataGridViewTextBoxColumn();
            Lat = new DataGridViewTextBoxColumn();
            Lon = new DataGridViewTextBoxColumn();
            groupBox3 = new GroupBox();
            groupBox2 = new GroupBox();
            groupBox1 = new GroupBox();
            groupBox5 = new GroupBox();
            groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dataGridView_control_values).BeginInit();
            groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dataGridView_t_ddi_linking).BeginInit();
            groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dataGridView_t_device).BeginInit();
            groupBox5.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)dataGridView_t_ddop_hierarchy).BeginInit();
            ((System.ComponentModel.ISupportInitialize)numeUpDown_setpoint).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dataGridView_GNSS).BeginInit();
            SuspendLayout();
            // 
            // groupBox3
            // 
            groupBox3.Controls.Add(dataGridView_control_values);
            groupBox3.Location = new Point(392, 477);
            groupBox3.Name = "groupBox3";
            groupBox3.Size = new Size(675, 167);
            groupBox3.TabIndex = 8;
            groupBox3.TabStop = false;
            groupBox3.Text = "topic=\"t_pd_values_reliable\" (runtime process data)";
            // 
            // dataGridView_control_values
            // 
            dataGridView_control_values.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView_control_values.Columns.AddRange(new DataGridViewColumn[] { dataGridViewTextBoxColumn10, dataGridViewTextBoxColumn11, dataGridViewTextBoxColumn12, dataGridViewTextBoxColumn13, dataGridViewTextBoxColumn14, dataGridViewTextBoxColumn15 });
            dataGridView_control_values.Location = new Point(6, 22);
            dataGridView_control_values.Margin = new Padding(2);
            dataGridView_control_values.Name = "dataGridView_control_values";
            dataGridView_control_values.RowHeadersWidth = 51;
            dataGridView_control_values.Size = new Size(654, 140);
            dataGridView_control_values.TabIndex = 13;
            // 
            // dataGridViewTextBoxColumn10
            // 
            dataGridViewTextBoxColumn10.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn10.HeaderText = "My Name";
            dataGridViewTextBoxColumn10.MinimumWidth = 6;
            dataGridViewTextBoxColumn10.Name = "dataGridViewTextBoxColumn10";
            dataGridViewTextBoxColumn10.Width = 78;
            // 
            // dataGridViewTextBoxColumn11
            // 
            dataGridViewTextBoxColumn11.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn11.HeaderText = "my element nr";
            dataGridViewTextBoxColumn11.MinimumWidth = 6;
            dataGridViewTextBoxColumn11.Name = "dataGridViewTextBoxColumn11";
            dataGridViewTextBoxColumn11.Width = 90;
            // 
            // dataGridViewTextBoxColumn12
            // 
            dataGridViewTextBoxColumn12.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            dataGridViewTextBoxColumn12.HeaderText = "Handling feature";
            dataGridViewTextBoxColumn12.MinimumWidth = 6;
            dataGridViewTextBoxColumn12.Name = "dataGridViewTextBoxColumn12";
            // 
            // dataGridViewTextBoxColumn13
            // 
            dataGridViewTextBoxColumn13.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn13.HeaderText = "Handling group";
            dataGridViewTextBoxColumn13.MinimumWidth = 6;
            dataGridViewTextBoxColumn13.Name = "dataGridViewTextBoxColumn13";
            dataGridViewTextBoxColumn13.Width = 106;
            // 
            // dataGridViewTextBoxColumn14
            // 
            dataGridViewTextBoxColumn14.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn14.HeaderText = "Value";
            dataGridViewTextBoxColumn14.MinimumWidth = 6;
            dataGridViewTextBoxColumn14.Name = "dataGridViewTextBoxColumn14";
            dataGridViewTextBoxColumn14.Width = 60;
            // 
            // dataGridViewTextBoxColumn15
            // 
            dataGridViewTextBoxColumn15.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn15.HeaderText = "Unit";
            dataGridViewTextBoxColumn15.MinimumWidth = 6;
            dataGridViewTextBoxColumn15.Name = "dataGridViewTextBoxColumn15";
            dataGridViewTextBoxColumn15.Width = 54;
            // 
            // groupBox2
            // 
            groupBox2.Controls.Add(dataGridView_t_ddi_linking);
            groupBox2.Location = new Point(392, 343);
            groupBox2.Name = "groupBox2";
            groupBox2.Size = new Size(674, 127);
            groupBox2.TabIndex = 8;
            groupBox2.TabStop = false;
            groupBox2.Text = "topic=\"t_ddi_linking\" (like DDOP - putting DDIs in DETs) ";
            // 
            // dataGridView_t_control_cababilities
            // 
            dataGridView_t_ddi_linking.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView_t_ddi_linking.Columns.AddRange(new DataGridViewColumn[] { dataGridViewTextBoxColumn2, dataGridViewTextBoxColumn3, dataGridViewTextBoxColumn6, dataGridViewTextBoxColumn7, dataGridViewTextBoxColumn8 });
            dataGridView_t_ddi_linking.Location = new Point(6, 22);
            dataGridView_t_ddi_linking.Margin = new Padding(2);
            dataGridView_t_ddi_linking.Name = "dataGridView_t_control_cababilities";
            dataGridView_t_ddi_linking.RowHeadersWidth = 51;
            dataGridView_t_ddi_linking.Size = new Size(566, 91);
            dataGridView_t_ddi_linking.TabIndex = 12;
            // 
            // dataGridViewTextBoxColumn2
            // 
            dataGridViewTextBoxColumn2.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn2.HeaderText = "My Name";
            dataGridViewTextBoxColumn2.MinimumWidth = 6;
            dataGridViewTextBoxColumn2.Name = "dataGridViewTextBoxColumn2";
            dataGridViewTextBoxColumn2.Width = 78;
            // 
            // dataGridViewTextBoxColumn3
            // 
            dataGridViewTextBoxColumn3.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn3.HeaderText = "my element nr";
            dataGridViewTextBoxColumn3.MinimumWidth = 6;
            dataGridViewTextBoxColumn3.Name = "dataGridViewTextBoxColumn3";
            dataGridViewTextBoxColumn3.Width = 90;
            // 
            // dataGridViewTextBoxColumn6
            // 
            dataGridViewTextBoxColumn6.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn6.HeaderText = "Handling group";
            dataGridViewTextBoxColumn6.MinimumWidth = 6;
            dataGridViewTextBoxColumn6.Name = "dataGridViewTextBoxColumn6";
            dataGridViewTextBoxColumn6.Width = 106;
            // 
            // dataGridViewTextBoxColumn7
            // 
            dataGridViewTextBoxColumn7.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn7.HeaderText = "Option nr";
            dataGridViewTextBoxColumn7.MinimumWidth = 6;
            dataGridViewTextBoxColumn7.Name = "dataGridViewTextBoxColumn7";
            dataGridViewTextBoxColumn7.Width = 77;
            // 
            // dataGridViewTextBoxColumn8
            // 
            dataGridViewTextBoxColumn8.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            dataGridViewTextBoxColumn8.HeaderText = "Unit";
            dataGridViewTextBoxColumn8.MinimumWidth = 6;
            dataGridViewTextBoxColumn8.Name = "dataGridViewTextBoxColumn8";
            // 
            // groupBox1
            // 
            groupBox1.Controls.Add(dataGridView_t_device);
            groupBox1.Location = new Point(392, 208);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(674, 129);
            groupBox1.TabIndex = 7;
            groupBox1.TabStop = false;
            groupBox1.Text = "topic=\"t_device\"";
            // 
            // dataGridView_t_device
            // 
            dataGridView_t_device.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView_t_device.Columns.AddRange(new DataGridViewColumn[] { Column_id, Column_designator, Column_softwareversion, Column_NAME, Column_serialnumber, Column_structurelabel, Column_localizationlabel });
            dataGridView_t_device.Location = new Point(6, 22);
            dataGridView_t_device.Margin = new Padding(2);
            dataGridView_t_device.Name = "dataGridView_t_device";
            dataGridView_t_device.RowHeadersWidth = 51;
            dataGridView_t_device.Size = new Size(654, 91);
            dataGridView_t_device.TabIndex = 11;
            // 
            // Column_id
            // 
            Column_id.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_id.HeaderText = "ID";
            Column_id.MinimumWidth = 6;
            Column_id.Name = "Column_id";
            Column_id.Width = 43;
            // 
            // Column_designator
            // 
            Column_designator.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_designator.HeaderText = "designator";
            Column_designator.MinimumWidth = 6;
            Column_designator.Name = "Column_designator";
            Column_designator.Width = 88;
            // 
            // Column_softwareversion
            // 
            Column_softwareversion.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_softwareversion.HeaderText = "V. software";
            Column_softwareversion.MinimumWidth = 6;
            Column_softwareversion.Name = "Column_softwareversion";
            Column_softwareversion.Width = 90;
            // 
            // Column_NAME
            // 
            Column_NAME.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_NAME.HeaderText = "NAME";
            Column_NAME.MinimumWidth = 6;
            Column_NAME.Name = "Column_NAME";
            Column_NAME.Width = 66;
            // 
            // Column_serialnumber
            // 
            Column_serialnumber.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_serialnumber.HeaderText = "serialnumber";
            Column_serialnumber.MinimumWidth = 6;
            Column_serialnumber.Name = "Column_serialnumber";
            Column_serialnumber.Width = 101;
            // 
            // Column_structurelabel
            // 
            Column_structurelabel.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_structurelabel.HeaderText = "structurelabel";
            Column_structurelabel.MinimumWidth = 6;
            Column_structurelabel.Name = "Column_structurelabel";
            Column_structurelabel.Width = 104;
            // 
            // Column_localizationlabel
            // 
            Column_localizationlabel.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            Column_localizationlabel.HeaderText = "localizationlabel";
            Column_localizationlabel.MinimumWidth = 6;
            Column_localizationlabel.Name = "Column_localizationlabel";
            // 
            // groupBox5
            // 
            groupBox5.Controls.Add(dataGridView_t_ddop_hierarchy);
            groupBox5.Location = new Point(392, 9);
            groupBox5.Name = "groupBox5";
            groupBox5.Size = new Size(674, 192);
            groupBox5.TabIndex = 8;
            groupBox5.TabStop = false;
            groupBox5.Text = "topic=\"t_ddop_hierarchy\" (like DDOP - hierarchy of DETs) ";
            // 
            // dataGridView_t_ddop_hierarchy
            // 
            dataGridView_t_ddop_hierarchy.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView_t_ddop_hierarchy.Columns.AddRange(new DataGridViewColumn[] { dataGridViewTextBoxColumn4, Column_my_element_ref_name, Column_element_ref_element_num, Column_parent_ref_name, Column_parent_ref__element_num, Column_connector_nr });
            dataGridView_t_ddop_hierarchy.Location = new Point(6, 22);
            dataGridView_t_ddop_hierarchy.Margin = new Padding(2);
            dataGridView_t_ddop_hierarchy.Name = "dataGridView_t_ddop_hierarchys";
            dataGridView_t_ddop_hierarchy.RowHeadersWidth = 51;
            dataGridView_t_ddop_hierarchy.Size = new Size(654, 159);
            dataGridView_t_ddop_hierarchy.TabIndex = 12;
            // 
            // dataGridViewTextBoxColumn4
            // 
            dataGridViewTextBoxColumn4.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            dataGridViewTextBoxColumn4.HeaderText = "Info";
            dataGridViewTextBoxColumn4.MinimumWidth = 6;
            dataGridViewTextBoxColumn4.Name = "dataGridViewTextBoxColumn4";
            dataGridViewTextBoxColumn4.Width = 53;
            // 
            // Column_my_element_ref_name
            // 
            Column_my_element_ref_name.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCellsExceptHeader;
            Column_my_element_ref_name.HeaderText = "My NAME";
            Column_my_element_ref_name.MinimumWidth = 100;
            Column_my_element_ref_name.Name = "Column_my_element_ref_name";
            // 
            // Column_element_ref_element_num
            // 
            Column_element_ref_element_num.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Column_element_ref_element_num.HeaderText = "My element nr";
            Column_element_ref_element_num.MinimumWidth = 6;
            Column_element_ref_element_num.Name = "Column_element_ref_element_num";
            Column_element_ref_element_num.Width = 90;
            // 
            // Column_parent_ref_name
            // 
            Column_parent_ref_name.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCellsExceptHeader;
            Column_parent_ref_name.HeaderText = "Parent's NAME";
            Column_parent_ref_name.MinimumWidth = 100;
            Column_parent_ref_name.Name = "Column_parent_ref_name";
            // 
            // Column_parent_ref__element_num
            // 
            Column_parent_ref__element_num.AutoSizeMode = DataGridViewAutoSizeColumnMode.None;
            Column_parent_ref__element_num.HeaderText = "Parent's element nr";
            Column_parent_ref__element_num.MinimumWidth = 6;
            Column_parent_ref__element_num.Name = "Column_parent_ref__element_num";
            Column_parent_ref__element_num.Width = 110;
            // 
            // Column_connector_nr
            // 
            Column_connector_nr.AutoSizeMode = DataGridViewAutoSizeColumnMode.Fill;
            Column_connector_nr.HeaderText = "connector nr";
            Column_connector_nr.MinimumWidth = 6;
            Column_connector_nr.Name = "Column_connector_nr";
            // 
            // startButton
            // 
            startButton.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            startButton.Font = new Font("Lucida Console", 24F, FontStyle.Regular, GraphicsUnit.Point, 0);
            startButton.Location = new Point(33, 521);
            startButton.Name = "startButton";
            startButton.Size = new Size(209, 60);
            startButton.TabIndex = 0;
            startButton.Text = "START DDS";
            startButton.UseVisualStyleBackColor = true;
            startButton.Click += start_button_Click;
            // 
            // numeUpDown_setpoint
            // 
            numeUpDown_setpoint.Location = new Point(266, 539);
            numeUpDown_setpoint.Name = "numeUpDown_setpoint";
            numeUpDown_setpoint.Size = new Size(120, 23);
            numeUpDown_setpoint.TabIndex = 10;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(266, 521);
            label1.Name = "label1";
            label1.Size = new Size(102, 15);
            label1.TabIndex = 11;
            label1.Text = "Sprayrate setpoint";
            // 
            // dataGridView_GNSS
            // 
            dataGridView_GNSS.AllowUserToAddRows = false;
            dataGridView_GNSS.AllowUserToDeleteRows = false;
            dataGridView_GNSS.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView_GNSS.Columns.AddRange(new DataGridViewColumn[] { dataGridViewTextBoxColumn5, Lat, Lon });
            dataGridView_GNSS.Location = new Point(33, 67);
            dataGridView_GNSS.Margin = new Padding(2);
            dataGridView_GNSS.Name = "dataGridView_GNSS";
            dataGridView_GNSS.ReadOnly = true;
            dataGridView_GNSS.RowHeadersWidth = 51;
            dataGridView_GNSS.Size = new Size(353, 95);
            dataGridView_GNSS.TabIndex = 13;
            // 
            // dataGridViewTextBoxColumn5
            // 
            dataGridViewTextBoxColumn5.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCellsExceptHeader;
            dataGridViewTextBoxColumn5.HeaderText = "NAME";
            dataGridViewTextBoxColumn5.MinimumWidth = 100;
            dataGridViewTextBoxColumn5.Name = "dataGridViewTextBoxColumn5";
            dataGridViewTextBoxColumn5.ReadOnly = true;
            // 
            // Lat
            // 
            Lat.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Lat.HeaderText = "Lat";
            Lat.Name = "Lat";
            Lat.ReadOnly = true;
            Lat.Width = 48;
            // 
            // Lon
            // 
            Lon.AutoSizeMode = DataGridViewAutoSizeColumnMode.AllCells;
            Lon.HeaderText = "Lon";
            Lon.Name = "Lon";
            Lon.ReadOnly = true;
            Lon.Width = 52;
            // 
            // HSI_Taskcontroller
            // 
            AutoScaleDimensions = new SizeF(96F, 96F);
            AutoScaleMode = AutoScaleMode.Dpi;
            ClientSize = new Size(1074, 697);
            Controls.Add(dataGridView_GNSS);
            Controls.Add(label1);
            Controls.Add(numeUpDown_setpoint);
            Controls.Add(groupBox5);
            Controls.Add(groupBox3);
            Controls.Add(groupBox2);
            Controls.Add(groupBox1);
            Controls.Add(startButton);
            Name = "HSI_Taskcontroller";
            Text = "HSI-Taskcontroller";
            Load += HSI_Taskcontroller_Load;
            groupBox3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dataGridView_control_values).EndInit();
            groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dataGridView_t_ddi_linking).EndInit();
            groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dataGridView_t_device).EndInit();
            groupBox5.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)dataGridView_t_ddop_hierarchy).EndInit();
            ((System.ComponentModel.ISupportInitialize)numeUpDown_setpoint).EndInit();
            ((System.ComponentModel.ISupportInitialize)dataGridView_GNSS).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button startButton;
        private DataGridView dataGridView_control_values;
        private DataGridView dataGridView_t_ddi_linking;
        private DataGridView dataGridView_t_device;
        private DataGridViewTextBoxColumn Column_id;
        private DataGridViewTextBoxColumn Column_designator;
        private DataGridViewTextBoxColumn Column_softwareversion;
        private DataGridViewTextBoxColumn Column_NAME;
        private DataGridViewTextBoxColumn Column_serialnumber;
        private DataGridViewTextBoxColumn Column_structurelabel;
        private DataGridViewTextBoxColumn Column_localizationlabel;
        private DataGridView dataGridView_t_ddop_hierarchy;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn4;
        private DataGridViewTextBoxColumn Column_my_element_ref_name;
        private DataGridViewTextBoxColumn Column_element_ref_element_num;
        private DataGridViewTextBoxColumn Column_parent_ref_name;
        private DataGridViewTextBoxColumn Column_parent_ref__element_num;
        private DataGridViewTextBoxColumn Column_connector_nr;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn10;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn11;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn12;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn13;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn14;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn15;
        private NumericUpDown numeUpDown_setpoint;
        private Label label1;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn2;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn3;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn6;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn7;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn8;
        private DataGridView dataGridView_GNSS;
        private DataGridViewTextBoxColumn dataGridViewTextBoxColumn5;
        private DataGridViewTextBoxColumn Lat;
        private DataGridViewTextBoxColumn Lon;
    }
}
