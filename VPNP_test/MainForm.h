#pragma once
#include "udp_arinc_data.h"
#include "ARINC429data.h"


namespace VPNPtest {

	using namespace System;
	using namespace System::Net::Sockets;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;


	typedef S_UDP_PACK_ODS_DATA UDP_OUT;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			Init();
			//
		}
		String^ IP_value = "192.168.2.255";
		String^ IP_port = "17300";
		uint16_t VPNPselected = 2;
		UdpClient^ udpClient;
		System::Net::IPEndPoint^ ipEndPoint;
	private: System::Windows::Forms::ToolStripButton^ btnTransmitOff;
	private: System::Windows::Forms::TabPage^ SVS;
	private: System::Windows::Forms::Label^ label28;
	private: System::Windows::Forms::NumericUpDown^ nm_speed_vert_svs;


	private: System::Windows::Forms::Label^ label29;
	private: System::Windows::Forms::NumericUpDown^ nm_M;

	private: System::Windows::Forms::Label^ label30;
	private: System::Windows::Forms::NumericUpDown^ nm_temp_h;

	private: System::Windows::Forms::Label^ label31;
	private: System::Windows::Forms::NumericUpDown^ nm_temp_r;

	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::NumericUpDown^ nm_Q;

	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::NumericUpDown^ nm_airspeed_prib;

	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::NumericUpDown^ nm_airspeed_true;

	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::NumericUpDown^ nm_H_qfe;


	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::NumericUpDown^ nm_H_qnh;

	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::NumericUpDown^ nm_H_abs;


	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::NumericUpDown^ nm_radio_altitude;

	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::NumericUpDown^ nm_altitude_trend;

	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::NumericUpDown^ nm_speed_trend;




	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::NumericUpDown^ nm_altitude_danger;

	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::NumericUpDown^ nm_Td2;

	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::NumericUpDown^ nm_Td1;

	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::NumericUpDown^ nm_P_h_stat;

	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::NumericUpDown^ nm_P_f;

	private: System::Windows::Forms::TabPage^ SNS;
	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::NumericUpDown^ nm_vertical_speed_sns;


	private: System::Windows::Forms::Label^ label47;
	private: System::Windows::Forms::NumericUpDown^ nm_speed_track_sns;

	private: System::Windows::Forms::Label^ label48;
	private: System::Windows::Forms::NumericUpDown^ nm_v_north_sns;

	private: System::Windows::Forms::Label^ label49;
	private: System::Windows::Forms::NumericUpDown^ nm_v_east_sns;

	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::NumericUpDown^ nm_pdop;


	private: System::Windows::Forms::Label^ label51;
	private: System::Windows::Forms::NumericUpDown^ nm_vdop;

	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::NumericUpDown^ nm_hdop;

	private: System::Windows::Forms::Label^ label53;

	private: System::Windows::Forms::Label^ label54;

	private: System::Windows::Forms::Label^ label55;
private: System::Windows::Forms::NumericUpDown^ nm_track_angle_sns;


	private: System::Windows::Forms::Label^ label56;
private: System::Windows::Forms::NumericUpDown^ nm_H_sns;








	private: System::Windows::Forms::Label^ label59;
private: System::Windows::Forms::RadioButton^ rb_QFE;
private: System::Windows::Forms::RadioButton^ rb_QNE;


private: System::Windows::Forms::RadioButton^ rb_QNH;
private: System::Windows::Forms::CheckBox^ cb_baro_update;



	private: System::Windows::Forms::CheckBox^ cb_generator_fail;


	private: System::Windows::Forms::CheckBox^ cb_engine_failure;

	private: System::Windows::Forms::CheckBox^ cb_apu_fire;

	private: System::Windows::Forms::CheckBox^ cb_engine_fire;

	private: System::Windows::Forms::TabPage^ RC;
private: System::Windows::Forms::CheckBox^ cb_elevator_trim_n;


private: System::Windows::Forms::CheckBox^ cb_ailerons_trim_n;
private: System::Windows::Forms::CheckBox^ cb_apu_work;




private: System::Windows::Forms::CheckBox^ cb_apu_start;


private: System::Windows::Forms::CheckBox^ cb_wow;


private: System::Windows::Forms::CheckBox^ cb_manual_mode;


private: System::Windows::Forms::CheckBox^ cb_engine_start;


private: System::Windows::Forms::CheckBox^ cb_rudder_trim_n;


	private: System::Windows::Forms::TabPage^ Params;
	private: System::Windows::Forms::Label^ label60;
private: System::Windows::Forms::NumericUpDown^ nm_pressure;

private: System::Windows::Forms::Label^ label61;
private: System::Windows::Forms::NumericUpDown^ nm_flash_page;

private: System::Windows::Forms::Label^ label62;
private: System::Windows::Forms::NumericUpDown^ nm_flash_block;







private: System::Windows::Forms::Label^ label66;
private: System::Windows::Forms::NumericUpDown^ nm_battery_current;

private: System::Windows::Forms::Label^ label67;
private: System::Windows::Forms::NumericUpDown^ nm_battery_voltage;

private: System::Windows::Forms::Label^ label68;
private: System::Windows::Forms::NumericUpDown^ nm_generator_current;

private: System::Windows::Forms::Label^ label69;
private: System::Windows::Forms::NumericUpDown^ nm_generator_voltage;

private: System::Windows::Forms::Label^ label70;
private: System::Windows::Forms::NumericUpDown^ nm_oil_pressure;

private: System::Windows::Forms::Label^ label71;
private: System::Windows::Forms::NumericUpDown^ nm_fuel_pressure;


private: System::Windows::Forms::Label^ label72;
private: System::Windows::Forms::NumericUpDown^ nm_fuel_consumption;

private: System::Windows::Forms::Label^ label73;
private: System::Windows::Forms::NumericUpDown^ nm_oil_temperature;

private: System::Windows::Forms::Label^ label74;
private: System::Windows::Forms::NumericUpDown^ nm_fuel_rem_l;

private: System::Windows::Forms::Label^ label75;
private: System::Windows::Forms::NumericUpDown^ nm_fuel_rem_r;

private: System::Windows::Forms::Label^ label76;
private: System::Windows::Forms::NumericUpDown^ nm_engine_torque;

private: System::Windows::Forms::Label^ label78;
private: System::Windows::Forms::Label^ label77;
private: System::Windows::Forms::NumericUpDown^ nm_engine_exhaust_temperature;

private: System::Windows::Forms::NumericUpDown^ nm_engine_rate;

private: System::Windows::Forms::Label^ label79;
private: System::Windows::Forms::NumericUpDown^ nm_flaps_position;

private: System::Windows::Forms::Label^ label80;
private: System::Windows::Forms::NumericUpDown^ nm_oil_radiator_position;

private: System::Windows::Forms::Label^ label81;
private: System::Windows::Forms::NumericUpDown^ nm_alpha;

private: System::Windows::Forms::Label^ label83;
private: System::Windows::Forms::Label^ label82;
private: System::Windows::Forms::NumericUpDown^ nm_alpha_max;

private: System::Windows::Forms::NumericUpDown^ nm_alpha_min;

private: System::Windows::Forms::Label^ label87;
private: System::Windows::Forms::Label^ label85;
private: System::Windows::Forms::Label^ label86;
private: System::Windows::Forms::Label^ label84;
private: System::Windows::Forms::NumericUpDown^ nm_speed_max;

private: System::Windows::Forms::NumericUpDown^ nm_ny_max;
private: System::Windows::Forms::NumericUpDown^ nm_speed_min;



private: System::Windows::Forms::NumericUpDown^ nm_ny_min;

private: System::Windows::Forms::TabPage^ Controllers;
private: System::Windows::Forms::Label^ label90;
private: System::Windows::Forms::Label^ label65;
private: System::Windows::Forms::NumericUpDown^ nm_elevator_position;
private: System::Windows::Forms::NumericUpDown^ nm_elevator_trim_pos;


private: System::Windows::Forms::Label^ label89;
private: System::Windows::Forms::Label^ label64;
private: System::Windows::Forms::NumericUpDown^ nm_ailerons_position;
private: System::Windows::Forms::NumericUpDown^ nm_ailerons_trim_pos;


private: System::Windows::Forms::Label^ label88;
private: System::Windows::Forms::NumericUpDown^ nm_rudder_position;

private: System::Windows::Forms::Label^ label63;
private: System::Windows::Forms::NumericUpDown^ nm_rudder_trim_pos;

private: System::Windows::Forms::Label^ label91;
private: System::Windows::Forms::NumericUpDown^ nm_slide_position;

private: System::Windows::Forms::Label^ label94;
private: System::Windows::Forms::NumericUpDown^ nm_adjust_roll_value;

private: System::Windows::Forms::Label^ label93;
private: System::Windows::Forms::NumericUpDown^ nm_adjust_pitch_value;

private: System::Windows::Forms::Label^ label92;
private: System::Windows::Forms::NumericUpDown^ nm_adjust_course_value;



private: System::Windows::Forms::NumericUpDown^ nm_L_clx;

private: System::Windows::Forms::NumericUpDown^ nm_B_clx;
private: System::Windows::Forms::NumericUpDown^ nm_L_clx_sns;

private: System::Windows::Forms::NumericUpDown^ nm_B_clx_sns;














	public:

	public:
		System::Net::IPAddress^ ip_addr = System::Net::IPAddress::Parse(IP_value);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			//if (out)
			//	delete out;
		}
	private: System::Windows::Forms::MenuStrip^ MainMenu;
	protected:

	private: System::Windows::Forms::ToolStripMenuItem^ FileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ExitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ TransmitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ TransmitOnToolStripMenuItem;
	protected:

	private: System::Windows::Forms::ToolStripSeparator^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ TransmitOffMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ TuningMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolBar;
	private: System::Windows::Forms::ToolStripButton^ btnTransmitOn;
private: System::Windows::Forms::TabControl^ tabControl;


	private: System::Windows::Forms::TabPage^ Mode;
	private: System::Windows::Forms::TabPage^ Failures;

	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::RadioButton^ rb_built_in_test;
	private: System::Windows::Forms::RadioButton^ rb_prep_done;
	private: System::Windows::Forms::RadioButton^ rb_nav;
	private: System::Windows::Forms::RadioButton^ rb_wait;
	private: System::Windows::Forms::RadioButton^ rb_ground_test;
	private: System::Windows::Forms::CheckBox^ cb_data_failure;
	private: System::Windows::Forms::CheckBox^ cb_vpnp_fail;
	private: System::Windows::Forms::CheckBox^ cb_data_link;
	private: System::Windows::Forms::CheckBox^ cb_ufos1_failure;
	private: System::Windows::Forms::CheckBox^ cb_cdmk_failure;
	private: System::Windows::Forms::CheckBox^ cb_cdmk_link;
	private: System::Windows::Forms::CheckBox^ cb_ufos1_link;
	private: System::Windows::Forms::CheckBox^ cb_ufos2_link;
	private: System::Windows::Forms::CheckBox^ cb_ufos2_valid;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ cb_mfi12r_link_fail;
	private: System::Windows::Forms::CheckBox^ cb_mfi12l_link_fail;
	private: System::Windows::Forms::CheckBox^ cb_mfi10_link_fail;
	private: System::Windows::Forms::TabPage^ INS;

	private: System::Windows::Forms::NumericUpDown^ nm_wind_angle_mag;
	private: System::Windows::Forms::NumericUpDown^ nm_wind_speed;
	private: System::Windows::Forms::NumericUpDown^ nm_drift_angle;
	private: System::Windows::Forms::Label^ label27;
	private: System::Windows::Forms::Label^ label26;
	private: System::Windows::Forms::Label^ label25;


	private: System::Windows::Forms::NumericUpDown^ nm_traj_slope;
	private: System::Windows::Forms::NumericUpDown^ nm_speed_vert;
	private: System::Windows::Forms::NumericUpDown^ nm_speed_vert_pot;
	private: System::Windows::Forms::NumericUpDown^ nm_v_north;
	private: System::Windows::Forms::NumericUpDown^ nm_v_east;
	private: System::Windows::Forms::NumericUpDown^ nm_speed_track;
	private: System::Windows::Forms::NumericUpDown^ nm_a_course;
	private: System::Windows::Forms::NumericUpDown^ nm_a_vert;
	private: System::Windows::Forms::NumericUpDown^ nm_H_otn;
	private: System::Windows::Forms::NumericUpDown^ nm_H_cmplx;
	private: System::Windows::Forms::Label^ label24;
	private: System::Windows::Forms::Label^ label23;
	private: System::Windows::Forms::Label^ label22;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::NumericUpDown^ nm_n_y;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::NumericUpDown^ nm_course_gyro;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::NumericUpDown^ nm_w_x;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::NumericUpDown^ nm_w_y;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ nm_w_z;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::NumericUpDown^ nm_n_x;
	private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::NumericUpDown^ nm_n_z;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::NumericUpDown^ nm_course_true;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ nm_course_track_mag;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::NumericUpDown^ nm_course_mag;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ nm_roll;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::NumericUpDown^ nm_pitch;
private: System::Windows::Forms::Timer^ timer;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		void Init(void);
		array<Byte>^ byteArray;
		IntPtr inptr;
		UDP_OUT* out;
		array<Byte>^ a429byteArray;
		IntPtr a429ptr;
		ARINC429values* a429;


		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->MainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TransmitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TransmitOnToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->TransmitOffMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->TuningMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolBar = (gcnew System::Windows::Forms::ToolStrip());
			this->btnTransmitOn = (gcnew System::Windows::Forms::ToolStripButton());
			this->btnTransmitOff = (gcnew System::Windows::Forms::ToolStripButton());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->Mode = (gcnew System::Windows::Forms::TabPage());
			this->rb_built_in_test = (gcnew System::Windows::Forms::RadioButton());
			this->rb_prep_done = (gcnew System::Windows::Forms::RadioButton());
			this->rb_nav = (gcnew System::Windows::Forms::RadioButton());
			this->rb_wait = (gcnew System::Windows::Forms::RadioButton());
			this->rb_ground_test = (gcnew System::Windows::Forms::RadioButton());
			this->Failures = (gcnew System::Windows::Forms::TabPage());
			this->cb_generator_fail = (gcnew System::Windows::Forms::CheckBox());
			this->cb_engine_failure = (gcnew System::Windows::Forms::CheckBox());
			this->cb_apu_fire = (gcnew System::Windows::Forms::CheckBox());
			this->cb_engine_fire = (gcnew System::Windows::Forms::CheckBox());
			this->cb_mfi12r_link_fail = (gcnew System::Windows::Forms::CheckBox());
			this->cb_mfi12l_link_fail = (gcnew System::Windows::Forms::CheckBox());
			this->cb_mfi10_link_fail = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->cb_ufos2_link = (gcnew System::Windows::Forms::CheckBox());
			this->cb_ufos2_valid = (gcnew System::Windows::Forms::CheckBox());
			this->cb_ufos1_link = (gcnew System::Windows::Forms::CheckBox());
			this->cb_cdmk_link = (gcnew System::Windows::Forms::CheckBox());
			this->cb_ufos1_failure = (gcnew System::Windows::Forms::CheckBox());
			this->cb_cdmk_failure = (gcnew System::Windows::Forms::CheckBox());
			this->cb_data_failure = (gcnew System::Windows::Forms::CheckBox());
			this->cb_vpnp_fail = (gcnew System::Windows::Forms::CheckBox());
			this->cb_data_link = (gcnew System::Windows::Forms::CheckBox());
			this->INS = (gcnew System::Windows::Forms::TabPage());
			this->nm_L_clx = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_B_clx = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_wind_angle_mag = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_wind_speed = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_drift_angle = (gcnew System::Windows::Forms::NumericUpDown());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->nm_traj_slope = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_speed_vert = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_speed_vert_pot = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_v_north = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_v_east = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_speed_track = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_a_course = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_a_vert = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_H_otn = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_H_cmplx = (gcnew System::Windows::Forms::NumericUpDown());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->nm_n_y = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->nm_course_gyro = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->nm_w_x = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->nm_w_y = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->nm_w_z = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->nm_n_x = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->nm_n_z = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->nm_course_true = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->nm_course_track_mag = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->nm_course_mag = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nm_roll = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nm_pitch = (gcnew System::Windows::Forms::NumericUpDown());
			this->SVS = (gcnew System::Windows::Forms::TabPage());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->nm_radio_altitude = (gcnew System::Windows::Forms::NumericUpDown());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->nm_altitude_trend = (gcnew System::Windows::Forms::NumericUpDown());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->nm_speed_trend = (gcnew System::Windows::Forms::NumericUpDown());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->nm_altitude_danger = (gcnew System::Windows::Forms::NumericUpDown());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->nm_Td2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->nm_Td1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->nm_P_h_stat = (gcnew System::Windows::Forms::NumericUpDown());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->nm_P_f = (gcnew System::Windows::Forms::NumericUpDown());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->nm_speed_vert_svs = (gcnew System::Windows::Forms::NumericUpDown());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->nm_M = (gcnew System::Windows::Forms::NumericUpDown());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->nm_temp_h = (gcnew System::Windows::Forms::NumericUpDown());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->nm_temp_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->nm_Q = (gcnew System::Windows::Forms::NumericUpDown());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->nm_airspeed_prib = (gcnew System::Windows::Forms::NumericUpDown());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->nm_airspeed_true = (gcnew System::Windows::Forms::NumericUpDown());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->nm_H_qfe = (gcnew System::Windows::Forms::NumericUpDown());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->nm_H_qnh = (gcnew System::Windows::Forms::NumericUpDown());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->nm_H_abs = (gcnew System::Windows::Forms::NumericUpDown());
			this->SNS = (gcnew System::Windows::Forms::TabPage());
			this->nm_L_clx_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_B_clx_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->cb_baro_update = (gcnew System::Windows::Forms::CheckBox());
			this->rb_QNE = (gcnew System::Windows::Forms::RadioButton());
			this->rb_QNH = (gcnew System::Windows::Forms::RadioButton());
			this->rb_QFE = (gcnew System::Windows::Forms::RadioButton());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->nm_H_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->nm_track_angle_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->nm_vertical_speed_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->nm_speed_track_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->nm_v_north_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->nm_v_east_sns = (gcnew System::Windows::Forms::NumericUpDown());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->nm_pdop = (gcnew System::Windows::Forms::NumericUpDown());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->nm_vdop = (gcnew System::Windows::Forms::NumericUpDown());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->nm_hdop = (gcnew System::Windows::Forms::NumericUpDown());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->RC = (gcnew System::Windows::Forms::TabPage());
			this->cb_apu_work = (gcnew System::Windows::Forms::CheckBox());
			this->cb_apu_start = (gcnew System::Windows::Forms::CheckBox());
			this->cb_wow = (gcnew System::Windows::Forms::CheckBox());
			this->cb_manual_mode = (gcnew System::Windows::Forms::CheckBox());
			this->cb_engine_start = (gcnew System::Windows::Forms::CheckBox());
			this->cb_rudder_trim_n = (gcnew System::Windows::Forms::CheckBox());
			this->cb_elevator_trim_n = (gcnew System::Windows::Forms::CheckBox());
			this->cb_ailerons_trim_n = (gcnew System::Windows::Forms::CheckBox());
			this->Params = (gcnew System::Windows::Forms::TabPage());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->nm_speed_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->nm_ny_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->nm_speed_min = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_alpha_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_ny_min = (gcnew System::Windows::Forms::NumericUpDown());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->nm_alpha_min = (gcnew System::Windows::Forms::NumericUpDown());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->nm_alpha = (gcnew System::Windows::Forms::NumericUpDown());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->nm_oil_radiator_position = (gcnew System::Windows::Forms::NumericUpDown());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->nm_flaps_position = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_engine_exhaust_temperature = (gcnew System::Windows::Forms::NumericUpDown());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->nm_engine_rate = (gcnew System::Windows::Forms::NumericUpDown());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->nm_engine_torque = (gcnew System::Windows::Forms::NumericUpDown());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->nm_fuel_rem_r = (gcnew System::Windows::Forms::NumericUpDown());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->nm_fuel_rem_l = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_oil_temperature = (gcnew System::Windows::Forms::NumericUpDown());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->nm_fuel_consumption = (gcnew System::Windows::Forms::NumericUpDown());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->nm_fuel_pressure = (gcnew System::Windows::Forms::NumericUpDown());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->nm_oil_pressure = (gcnew System::Windows::Forms::NumericUpDown());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->nm_generator_voltage = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_generator_current = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_battery_voltage = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_battery_current = (gcnew System::Windows::Forms::NumericUpDown());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->nm_flash_block = (gcnew System::Windows::Forms::NumericUpDown());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->nm_flash_page = (gcnew System::Windows::Forms::NumericUpDown());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->nm_pressure = (gcnew System::Windows::Forms::NumericUpDown());
			this->Controllers = (gcnew System::Windows::Forms::TabPage());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->nm_adjust_roll_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->nm_adjust_pitch_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->nm_adjust_course_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->nm_slide_position = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_elevator_position = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_elevator_trim_pos = (gcnew System::Windows::Forms::NumericUpDown());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->nm_ailerons_position = (gcnew System::Windows::Forms::NumericUpDown());
			this->nm_ailerons_trim_pos = (gcnew System::Windows::Forms::NumericUpDown());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->nm_rudder_position = (gcnew System::Windows::Forms::NumericUpDown());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->nm_rudder_trim_pos = (gcnew System::Windows::Forms::NumericUpDown());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->MainMenu->SuspendLayout();
			this->toolBar->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->Mode->SuspendLayout();
			this->Failures->SuspendLayout();
			this->INS->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_L_clx))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_B_clx))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_wind_angle_mag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_wind_speed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_drift_angle))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_traj_slope))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_vert))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_vert_pot))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_north))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_east))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_track))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_a_course))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_a_vert))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_otn))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_cmplx))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_n_y))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_gyro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_w_x))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_w_y))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_w_z))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_n_x))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_n_z))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_true))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_track_mag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_mag))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_roll))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_pitch))->BeginInit();
			this->SVS->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_radio_altitude))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_altitude_trend))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_trend))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_altitude_danger))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_Td2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_Td1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_P_h_stat))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_P_f))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_vert_svs))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_M))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_temp_h))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_temp_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_Q))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_airspeed_prib))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_airspeed_true))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_qfe))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_qnh))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_abs))->BeginInit();
			this->SNS->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_L_clx_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_B_clx_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_track_angle_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_vertical_speed_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_track_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_north_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_east_sns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_pdop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_vdop))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_hdop))->BeginInit();
			this->RC->SuspendLayout();
			this->Params->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ny_max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_min))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_alpha_max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ny_min))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_alpha_min))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_alpha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_oil_radiator_position))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_flaps_position))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_engine_exhaust_temperature))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_engine_rate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_engine_torque))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_rem_r))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_rem_l))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_oil_temperature))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_consumption))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_pressure))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_oil_pressure))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_generator_voltage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_generator_current))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_battery_voltage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_battery_current))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_flash_block))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_flash_page))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_pressure))->BeginInit();
			this->Controllers->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_adjust_roll_value))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_adjust_pitch_value))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_adjust_course_value))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_slide_position))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_elevator_position))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_elevator_trim_pos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ailerons_position))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ailerons_trim_pos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_rudder_position))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_rudder_trim_pos))->BeginInit();
			this->SuspendLayout();
			// 
			// MainMenu
			// 
			this->MainMenu->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->MainMenu->ImageScalingSize = System::Drawing::Size(24, 24);
			this->MainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->FileToolStripMenuItem,
					this->TransmitToolStripMenuItem, this->TuningMenuItem
			});
			this->MainMenu->Location = System::Drawing::Point(0, 0);
			this->MainMenu->Name = L"MainMenu";
			this->MainMenu->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->MainMenu->Size = System::Drawing::Size(778, 33);
			this->MainMenu->TabIndex = 0;
			this->MainMenu->Text = L"menuStrip1";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ExitToolStripMenuItem });
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(69, 29);
			this->FileToolStripMenuItem->Text = L"Файл";
			// 
			// ExitToolStripMenuItem
			// 
			this->ExitToolStripMenuItem->Name = L"ExitToolStripMenuItem";
			this->ExitToolStripMenuItem->Size = System::Drawing::Size(166, 34);
			this->ExitToolStripMenuItem->Text = L"Выход";
			this->ExitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::ExitToolStripMenuItem_Click);
			// 
			// TransmitToolStripMenuItem
			// 
			this->TransmitToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->TransmitOnToolStripMenuItem,
					this->toolStripMenuItem1, this->TransmitOffMenuItem
			});
			this->TransmitToolStripMenuItem->Name = L"TransmitToolStripMenuItem";
			this->TransmitToolStripMenuItem->Size = System::Drawing::Size(108, 29);
			this->TransmitToolStripMenuItem->Text = L"Передача";
			// 
			// TransmitOnToolStripMenuItem
			// 
			this->TransmitOnToolStripMenuItem->Name = L"TransmitOnToolStripMenuItem";
			this->TransmitOnToolStripMenuItem->Size = System::Drawing::Size(206, 34);
			this->TransmitOnToolStripMenuItem->Text = L"Включить";
			this->TransmitOnToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::Transmit);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(203, 6);
			// 
			// TransmitOffMenuItem
			// 
			this->TransmitOffMenuItem->Enabled = false;
			this->TransmitOffMenuItem->Name = L"TransmitOffMenuItem";
			this->TransmitOffMenuItem->Size = System::Drawing::Size(206, 34);
			this->TransmitOffMenuItem->Text = L"Выключить";
			this->TransmitOffMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TransmitOff);
			// 
			// TuningMenuItem
			// 
			this->TuningMenuItem->Name = L"TuningMenuItem";
			this->TuningMenuItem->Size = System::Drawing::Size(115, 29);
			this->TuningMenuItem->Text = L"Настройка";
			this->TuningMenuItem->Click += gcnew System::EventHandler(this, &MainForm::TuningMenuItem_Click);
			// 
			// toolBar
			// 
			this->toolBar->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolBar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->btnTransmitOn, this->btnTransmitOff });
			this->toolBar->Location = System::Drawing::Point(0, 33);
			this->toolBar->Name = L"toolBar";
			this->toolBar->Padding = System::Windows::Forms::Padding(0, 0, 3, 0);
			this->toolBar->Size = System::Drawing::Size(778, 33);
			this->toolBar->TabIndex = 1;
			this->toolBar->Text = L"toolStrip1";
			// 
			// btnTransmitOn
			// 
			this->btnTransmitOn->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btnTransmitOn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTransmitOn.Image")));
			this->btnTransmitOn->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnTransmitOn->Name = L"btnTransmitOn";
			this->btnTransmitOn->Size = System::Drawing::Size(34, 28);
			this->btnTransmitOn->Text = L"Включить передачу";
			this->btnTransmitOn->Click += gcnew System::EventHandler(this, &MainForm::Transmit);
			// 
			// btnTransmitOff
			// 
			this->btnTransmitOff->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->btnTransmitOff->Enabled = false;
			this->btnTransmitOff->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnTransmitOff.Image")));
			this->btnTransmitOff->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btnTransmitOff->Name = L"btnTransmitOff";
			this->btnTransmitOff->Size = System::Drawing::Size(34, 28);
			this->btnTransmitOff->Text = L"toolStripButton2";
			this->btnTransmitOff->Click += gcnew System::EventHandler(this, &MainForm::TransmitOff);
			// 
			// tabControl
			// 
			this->tabControl->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
			this->tabControl->Controls->Add(this->Mode);
			this->tabControl->Controls->Add(this->Failures);
			this->tabControl->Controls->Add(this->INS);
			this->tabControl->Controls->Add(this->SVS);
			this->tabControl->Controls->Add(this->SNS);
			this->tabControl->Controls->Add(this->RC);
			this->tabControl->Controls->Add(this->Params);
			this->tabControl->Controls->Add(this->Controllers);
			this->tabControl->Location = System::Drawing::Point(0, 83);
			this->tabControl->Multiline = true;
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(779, 811);
			this->tabControl->TabIndex = 2;
			// 
			// Mode
			// 
			this->Mode->AutoScroll = true;
			this->Mode->Controls->Add(this->rb_built_in_test);
			this->Mode->Controls->Add(this->rb_prep_done);
			this->Mode->Controls->Add(this->rb_nav);
			this->Mode->Controls->Add(this->rb_wait);
			this->Mode->Controls->Add(this->rb_ground_test);
			this->Mode->Location = System::Drawing::Point(4, 32);
			this->Mode->Name = L"Mode";
			this->Mode->Padding = System::Windows::Forms::Padding(3);
			this->Mode->Size = System::Drawing::Size(771, 775);
			this->Mode->TabIndex = 0;
			this->Mode->Text = L"Режим";
			this->Mode->UseVisualStyleBackColor = true;
			// 
			// rb_built_in_test
			// 
			this->rb_built_in_test->AutoSize = true;
			this->rb_built_in_test->Checked = true;
			this->rb_built_in_test->Location = System::Drawing::Point(8, 6);
			this->rb_built_in_test->Name = L"rb_built_in_test";
			this->rb_built_in_test->Size = System::Drawing::Size(250, 24);
			this->rb_built_in_test->TabIndex = 9;
			this->rb_built_in_test->TabStop = true;
			this->rb_built_in_test->Text = L"Тест начального включения";
			this->rb_built_in_test->UseVisualStyleBackColor = true;
			this->rb_built_in_test->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_built_in_test_CheckedChanged);
			// 
			// rb_prep_done
			// 
			this->rb_prep_done->AutoSize = true;
			this->rb_prep_done->Location = System::Drawing::Point(8, 95);
			this->rb_prep_done->Name = L"rb_prep_done";
			this->rb_prep_done->Size = System::Drawing::Size(214, 24);
			this->rb_prep_done->TabIndex = 5;
			this->rb_prep_done->Text = L"Подготовка завершена";
			this->rb_prep_done->UseVisualStyleBackColor = true;
			this->rb_prep_done->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_prep_done_CheckedChanged);
			// 
			// rb_nav
			// 
			this->rb_nav->AutoSize = true;
			this->rb_nav->Location = System::Drawing::Point(8, 126);
			this->rb_nav->Name = L"rb_nav";
			this->rb_nav->Size = System::Drawing::Size(116, 24);
			this->rb_nav->TabIndex = 6;
			this->rb_nav->Text = L"Навигация";
			this->rb_nav->UseVisualStyleBackColor = true;
			this->rb_nav->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_nav_CheckedChanged);
			// 
			// rb_wait
			// 
			this->rb_wait->AutoSize = true;
			this->rb_wait->Location = System::Drawing::Point(8, 66);
			this->rb_wait->Name = L"rb_wait";
			this->rb_wait->Size = System::Drawing::Size(113, 24);
			this->rb_wait->TabIndex = 7;
			this->rb_wait->Text = L"Ожидание";
			this->rb_wait->UseVisualStyleBackColor = true;
			this->rb_wait->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_wait_CheckedChanged);
			// 
			// rb_ground_test
			// 
			this->rb_ground_test->AutoSize = true;
			this->rb_ground_test->Location = System::Drawing::Point(8, 35);
			this->rb_ground_test->Name = L"rb_ground_test";
			this->rb_ground_test->Size = System::Drawing::Size(188, 24);
			this->rb_ground_test->TabIndex = 8;
			this->rb_ground_test->Text = L"Наземный контроль";
			this->rb_ground_test->UseVisualStyleBackColor = true;
			this->rb_ground_test->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_ground_test_CheckedChanged);
			// 
			// Failures
			// 
			this->Failures->Controls->Add(this->cb_generator_fail);
			this->Failures->Controls->Add(this->cb_engine_failure);
			this->Failures->Controls->Add(this->cb_apu_fire);
			this->Failures->Controls->Add(this->cb_engine_fire);
			this->Failures->Controls->Add(this->cb_mfi12r_link_fail);
			this->Failures->Controls->Add(this->cb_mfi12l_link_fail);
			this->Failures->Controls->Add(this->cb_mfi10_link_fail);
			this->Failures->Controls->Add(this->checkBox1);
			this->Failures->Controls->Add(this->checkBox2);
			this->Failures->Controls->Add(this->cb_ufos2_link);
			this->Failures->Controls->Add(this->cb_ufos2_valid);
			this->Failures->Controls->Add(this->cb_ufos1_link);
			this->Failures->Controls->Add(this->cb_cdmk_link);
			this->Failures->Controls->Add(this->cb_ufos1_failure);
			this->Failures->Controls->Add(this->cb_cdmk_failure);
			this->Failures->Controls->Add(this->cb_data_failure);
			this->Failures->Controls->Add(this->cb_vpnp_fail);
			this->Failures->Controls->Add(this->cb_data_link);
			this->Failures->Location = System::Drawing::Point(4, 32);
			this->Failures->Name = L"Failures";
			this->Failures->Padding = System::Windows::Forms::Padding(3);
			this->Failures->Size = System::Drawing::Size(771, 775);
			this->Failures->TabIndex = 1;
			this->Failures->Text = L"Отказы";
			this->Failures->UseVisualStyleBackColor = true;
			// 
			// cb_generator_fail
			// 
			this->cb_generator_fail->AutoSize = true;
			this->cb_generator_fail->Location = System::Drawing::Point(386, 107);
			this->cb_generator_fail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_generator_fail->Name = L"cb_generator_fail";
			this->cb_generator_fail->Size = System::Drawing::Size(173, 24);
			this->cb_generator_fail->TabIndex = 18;
			this->cb_generator_fail->Text = L"Отказ генератора";
			this->cb_generator_fail->UseVisualStyleBackColor = true;
			this->cb_generator_fail->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_generator_fail_CheckedChanged);
			// 
			// cb_engine_failure
			// 
			this->cb_engine_failure->AutoSize = true;
			this->cb_engine_failure->Location = System::Drawing::Point(386, 74);
			this->cb_engine_failure->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_engine_failure->Name = L"cb_engine_failure";
			this->cb_engine_failure->Size = System::Drawing::Size(167, 24);
			this->cb_engine_failure->TabIndex = 17;
			this->cb_engine_failure->Text = L"Отказ двигателя";
			this->cb_engine_failure->UseVisualStyleBackColor = true;
			this->cb_engine_failure->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_engine_failure_CheckedChanged);
			// 
			// cb_apu_fire
			// 
			this->cb_apu_fire->AutoSize = true;
			this->cb_apu_fire->Location = System::Drawing::Point(386, 41);
			this->cb_apu_fire->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_apu_fire->Name = L"cb_apu_fire";
			this->cb_apu_fire->Size = System::Drawing::Size(121, 24);
			this->cb_apu_fire->TabIndex = 16;
			this->cb_apu_fire->Text = L"Пожар ВСУ";
			this->cb_apu_fire->UseVisualStyleBackColor = true;
			this->cb_apu_fire->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_apu_fire_CheckedChanged);
			// 
			// cb_engine_fire
			// 
			this->cb_engine_fire->AutoSize = true;
			this->cb_engine_fire->Location = System::Drawing::Point(386, 8);
			this->cb_engine_fire->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_engine_fire->Name = L"cb_engine_fire";
			this->cb_engine_fire->Size = System::Drawing::Size(171, 24);
			this->cb_engine_fire->TabIndex = 15;
			this->cb_engine_fire->Text = L"Пожар двигателя";
			this->cb_engine_fire->UseVisualStyleBackColor = true;
			this->cb_engine_fire->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_engine_fire_CheckedChanged);
			// 
			// cb_mfi12r_link_fail
			// 
			this->cb_mfi12r_link_fail->AutoSize = true;
			this->cb_mfi12r_link_fail->Location = System::Drawing::Point(7, 435);
			this->cb_mfi12r_link_fail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_mfi12r_link_fail->Name = L"cb_mfi12r_link_fail";
			this->cb_mfi12r_link_fail->Size = System::Drawing::Size(257, 24);
			this->cb_mfi12r_link_fail->TabIndex = 14;
			this->cb_mfi12r_link_fail->Text = L"Нет данных от МФИ-12 прав.";
			this->cb_mfi12r_link_fail->UseVisualStyleBackColor = true;
			this->cb_mfi12r_link_fail->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_mfi12r_link_fail_CheckedChanged);
			// 
			// cb_mfi12l_link_fail
			// 
			this->cb_mfi12l_link_fail->AutoSize = true;
			this->cb_mfi12l_link_fail->Location = System::Drawing::Point(7, 402);
			this->cb_mfi12l_link_fail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_mfi12l_link_fail->Name = L"cb_mfi12l_link_fail";
			this->cb_mfi12l_link_fail->Size = System::Drawing::Size(249, 24);
			this->cb_mfi12l_link_fail->TabIndex = 13;
			this->cb_mfi12l_link_fail->Text = L"Нет данных от МФИ-12 лев.";
			this->cb_mfi12l_link_fail->UseVisualStyleBackColor = true;
			this->cb_mfi12l_link_fail->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_mfi12l_link_fail_CheckedChanged);
			// 
			// cb_mfi10_link_fail
			// 
			this->cb_mfi10_link_fail->AutoSize = true;
			this->cb_mfi10_link_fail->Location = System::Drawing::Point(7, 369);
			this->cb_mfi10_link_fail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_mfi10_link_fail->Name = L"cb_mfi10_link_fail";
			this->cb_mfi10_link_fail->Size = System::Drawing::Size(213, 24);
			this->cb_mfi10_link_fail->TabIndex = 12;
			this->cb_mfi10_link_fail->Text = L"Нет данных от МФИ-10";
			this->cb_mfi10_link_fail->UseVisualStyleBackColor = true;
			this->cb_mfi10_link_fail->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_mfi10_link_fail_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(7, 336);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(302, 24);
			this->checkBox1->TabIndex = 11;
			this->checkBox1->Text = L"Отказ связи с УФОС-01 по CAN №2";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(7, 303);
			this->checkBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(184, 24);
			this->checkBox2->TabIndex = 10;
			this->checkBox2->Text = L"Отказ УФОС-03 №3";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// cb_ufos2_link
			// 
			this->cb_ufos2_link->AutoSize = true;
			this->cb_ufos2_link->Location = System::Drawing::Point(7, 270);
			this->cb_ufos2_link->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_ufos2_link->Name = L"cb_ufos2_link";
			this->cb_ufos2_link->Size = System::Drawing::Size(302, 24);
			this->cb_ufos2_link->TabIndex = 9;
			this->cb_ufos2_link->Text = L"Отказ связи с УФОС-01 по CAN №2";
			this->cb_ufos2_link->UseVisualStyleBackColor = true;
			this->cb_ufos2_link->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_ufos2_link_CheckedChanged);
			// 
			// cb_ufos2_valid
			// 
			this->cb_ufos2_valid->AutoSize = true;
			this->cb_ufos2_valid->Location = System::Drawing::Point(7, 237);
			this->cb_ufos2_valid->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_ufos2_valid->Name = L"cb_ufos2_valid";
			this->cb_ufos2_valid->Size = System::Drawing::Size(184, 24);
			this->cb_ufos2_valid->TabIndex = 8;
			this->cb_ufos2_valid->Text = L"Отказ УФОС-01 №2";
			this->cb_ufos2_valid->UseVisualStyleBackColor = true;
			this->cb_ufos2_valid->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_ufos2_valid_CheckedChanged);
			// 
			// cb_ufos1_link
			// 
			this->cb_ufos1_link->AutoSize = true;
			this->cb_ufos1_link->Location = System::Drawing::Point(7, 204);
			this->cb_ufos1_link->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_ufos1_link->Name = L"cb_ufos1_link";
			this->cb_ufos1_link->Size = System::Drawing::Size(302, 24);
			this->cb_ufos1_link->TabIndex = 7;
			this->cb_ufos1_link->Text = L"Отказ связи с УФОС-01 по CAN №1";
			this->cb_ufos1_link->UseVisualStyleBackColor = true;
			this->cb_ufos1_link->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_ufos1_link_CheckedChanged);
			// 
			// cb_cdmk_link
			// 
			this->cb_cdmk_link->AutoSize = true;
			this->cb_cdmk_link->Location = System::Drawing::Point(7, 138);
			this->cb_cdmk_link->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_cdmk_link->Name = L"cb_cdmk_link";
			this->cb_cdmk_link->Size = System::Drawing::Size(250, 24);
			this->cb_cdmk_link->TabIndex = 6;
			this->cb_cdmk_link->Text = L"Отказ связи с ЦДМК по CAN";
			this->cb_cdmk_link->UseVisualStyleBackColor = true;
			this->cb_cdmk_link->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_cdmk_link_CheckedChanged);
			// 
			// cb_ufos1_failure
			// 
			this->cb_ufos1_failure->AutoSize = true;
			this->cb_ufos1_failure->Location = System::Drawing::Point(7, 171);
			this->cb_ufos1_failure->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_ufos1_failure->Name = L"cb_ufos1_failure";
			this->cb_ufos1_failure->Size = System::Drawing::Size(184, 24);
			this->cb_ufos1_failure->TabIndex = 5;
			this->cb_ufos1_failure->Text = L"Отказ УФОС-01 №1";
			this->cb_ufos1_failure->UseVisualStyleBackColor = true;
			this->cb_ufos1_failure->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_ufos1_failure_CheckedChanged);
			// 
			// cb_cdmk_failure
			// 
			this->cb_cdmk_failure->AutoSize = true;
			this->cb_cdmk_failure->Location = System::Drawing::Point(7, 105);
			this->cb_cdmk_failure->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cb_cdmk_failure->Name = L"cb_cdmk_failure";
			this->cb_cdmk_failure->Size = System::Drawing::Size(132, 24);
			this->cb_cdmk_failure->TabIndex = 4;
			this->cb_cdmk_failure->Text = L"Отказ ЦДМК";
			this->cb_cdmk_failure->UseVisualStyleBackColor = true;
			this->cb_cdmk_failure->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_cdmk_failure_CheckedChanged);
			// 
			// cb_data_failure
			// 
			this->cb_data_failure->AutoSize = true;
			this->cb_data_failure->BackColor = System::Drawing::Color::Transparent;
			this->cb_data_failure->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_data_failure->Location = System::Drawing::Point(7, 39);
			this->cb_data_failure->Name = L"cb_data_failure";
			this->cb_data_failure->Size = System::Drawing::Size(189, 24);
			this->cb_data_failure->TabIndex = 1;
			this->cb_data_failure->Text = L"Отказ данных от ВС";
			this->cb_data_failure->UseVisualStyleBackColor = false;
			this->cb_data_failure->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_data_failure_CheckedChanged);
			// 
			// cb_vpnp_fail
			// 
			this->cb_vpnp_fail->AutoSize = true;
			this->cb_vpnp_fail->BackColor = System::Drawing::Color::Transparent;
			this->cb_vpnp_fail->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_vpnp_fail->Location = System::Drawing::Point(7, 6);
			this->cb_vpnp_fail->Name = L"cb_vpnp_fail";
			this->cb_vpnp_fail->Size = System::Drawing::Size(132, 24);
			this->cb_vpnp_fail->TabIndex = 2;
			this->cb_vpnp_fail->Text = L"Отказ ВПНП";
			this->cb_vpnp_fail->UseVisualStyleBackColor = false;
			this->cb_vpnp_fail->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_vpnp_fail_CheckedChanged);
			// 
			// cb_data_link
			// 
			this->cb_data_link->AutoSize = true;
			this->cb_data_link->BackColor = System::Drawing::Color::Transparent;
			this->cb_data_link->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_data_link->Location = System::Drawing::Point(7, 72);
			this->cb_data_link->Name = L"cb_data_link";
			this->cb_data_link->Size = System::Drawing::Size(173, 24);
			this->cb_data_link->TabIndex = 3;
			this->cb_data_link->Text = L"Нет данных от ВС";
			this->cb_data_link->UseVisualStyleBackColor = false;
			this->cb_data_link->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_data_link_CheckedChanged);
			// 
			// INS
			// 
			this->INS->Controls->Add(this->nm_L_clx);
			this->INS->Controls->Add(this->nm_B_clx);
			this->INS->Controls->Add(this->nm_wind_angle_mag);
			this->INS->Controls->Add(this->nm_wind_speed);
			this->INS->Controls->Add(this->nm_drift_angle);
			this->INS->Controls->Add(this->label27);
			this->INS->Controls->Add(this->label26);
			this->INS->Controls->Add(this->label25);
			this->INS->Controls->Add(this->nm_traj_slope);
			this->INS->Controls->Add(this->nm_speed_vert);
			this->INS->Controls->Add(this->nm_speed_vert_pot);
			this->INS->Controls->Add(this->nm_v_north);
			this->INS->Controls->Add(this->nm_v_east);
			this->INS->Controls->Add(this->nm_speed_track);
			this->INS->Controls->Add(this->nm_a_course);
			this->INS->Controls->Add(this->nm_a_vert);
			this->INS->Controls->Add(this->nm_H_otn);
			this->INS->Controls->Add(this->nm_H_cmplx);
			this->INS->Controls->Add(this->label24);
			this->INS->Controls->Add(this->label23);
			this->INS->Controls->Add(this->label22);
			this->INS->Controls->Add(this->label21);
			this->INS->Controls->Add(this->label20);
			this->INS->Controls->Add(this->label19);
			this->INS->Controls->Add(this->label18);
			this->INS->Controls->Add(this->label17);
			this->INS->Controls->Add(this->label16);
			this->INS->Controls->Add(this->label15);
			this->INS->Controls->Add(this->label14);
			this->INS->Controls->Add(this->label13);
			this->INS->Controls->Add(this->label12);
			this->INS->Controls->Add(this->nm_n_y);
			this->INS->Controls->Add(this->label11);
			this->INS->Controls->Add(this->nm_course_gyro);
			this->INS->Controls->Add(this->label10);
			this->INS->Controls->Add(this->nm_w_x);
			this->INS->Controls->Add(this->label9);
			this->INS->Controls->Add(this->nm_w_y);
			this->INS->Controls->Add(this->label8);
			this->INS->Controls->Add(this->nm_w_z);
			this->INS->Controls->Add(this->label7);
			this->INS->Controls->Add(this->nm_n_x);
			this->INS->Controls->Add(this->label6);
			this->INS->Controls->Add(this->nm_n_z);
			this->INS->Controls->Add(this->label5);
			this->INS->Controls->Add(this->nm_course_true);
			this->INS->Controls->Add(this->label4);
			this->INS->Controls->Add(this->nm_course_track_mag);
			this->INS->Controls->Add(this->label3);
			this->INS->Controls->Add(this->nm_course_mag);
			this->INS->Controls->Add(this->label2);
			this->INS->Controls->Add(this->nm_roll);
			this->INS->Controls->Add(this->label1);
			this->INS->Controls->Add(this->nm_pitch);
			this->INS->Location = System::Drawing::Point(4, 32);
			this->INS->Name = L"INS";
			this->INS->Size = System::Drawing::Size(771, 775);
			this->INS->TabIndex = 2;
			this->INS->Text = L"ИНС";
			this->INS->UseVisualStyleBackColor = true;
			// 
			// nm_L_clx
			// 
			this->nm_L_clx->DecimalPlaces = 6;
			this->nm_L_clx->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nm_L_clx->Location = System::Drawing::Point(561, 50);
			this->nm_L_clx->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			this->nm_L_clx->Name = L"nm_L_clx";
			this->nm_L_clx->Size = System::Drawing::Size(137, 26);
			this->nm_L_clx->TabIndex = 115;
			this->nm_L_clx->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 83010267, 0, 0, 393216 });
			this->nm_L_clx->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_L_clx_ValueChanged);
			// 
			// nm_B_clx
			// 
			this->nm_B_clx->DecimalPlaces = 6;
			this->nm_B_clx->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nm_B_clx->Location = System::Drawing::Point(561, 11);
			this->nm_B_clx->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			this->nm_B_clx->Name = L"nm_B_clx";
			this->nm_B_clx->Size = System::Drawing::Size(137, 26);
			this->nm_B_clx->TabIndex = 114;
			this->nm_B_clx->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 55104799, 0, 0, 393216 });
			this->nm_B_clx->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_B_clx_ValueChanged);
			// 
			// nm_wind_angle_mag
			// 
			this->nm_wind_angle_mag->Location = System::Drawing::Point(561, 551);
			this->nm_wind_angle_mag->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_wind_angle_mag->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_wind_angle_mag->Name = L"nm_wind_angle_mag";
			this->nm_wind_angle_mag->Size = System::Drawing::Size(83, 26);
			this->nm_wind_angle_mag->TabIndex = 113;
			this->nm_wind_angle_mag->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_wind_angle_mag_ValueChanged);
			// 
			// nm_wind_speed
			// 
			this->nm_wind_speed->Location = System::Drawing::Point(561, 509);
			this->nm_wind_speed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_wind_speed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_wind_speed->Name = L"nm_wind_speed";
			this->nm_wind_speed->Size = System::Drawing::Size(83, 26);
			this->nm_wind_speed->TabIndex = 112;
			this->nm_wind_speed->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_wind_speed_ValueChanged);
			// 
			// nm_drift_angle
			// 
			this->nm_drift_angle->Location = System::Drawing::Point(561, 463);
			this->nm_drift_angle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_drift_angle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_drift_angle->Name = L"nm_drift_angle";
			this->nm_drift_angle->Size = System::Drawing::Size(83, 26);
			this->nm_drift_angle->TabIndex = 111;
			this->nm_drift_angle->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_drift_angle_ValueChanged);
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(348, 549);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(158, 40);
			this->label27->TabIndex = 110;
			this->label27->Text = L"Магнитное \r\nнаправление ветра";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(349, 509);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(130, 20);
			this->label26->TabIndex = 109;
			this->label26->Text = L"Скорость ветра";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(8, 588);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(203, 40);
			this->label25->TabIndex = 108;
			this->label25->Text = L"Относительная\r\nбарометрическая высота";
			// 
			// nm_traj_slope
			// 
			this->nm_traj_slope->Location = System::Drawing::Point(561, 413);
			this->nm_traj_slope->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_traj_slope->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_traj_slope->Name = L"nm_traj_slope";
			this->nm_traj_slope->Size = System::Drawing::Size(83, 26);
			this->nm_traj_slope->TabIndex = 105;
			this->nm_traj_slope->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_traj_slope_ValueChanged);
			// 
			// nm_speed_vert
			// 
			this->nm_speed_vert->Location = System::Drawing::Point(561, 143);
			this->nm_speed_vert->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_vert->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_vert->Name = L"nm_speed_vert";
			this->nm_speed_vert->Size = System::Drawing::Size(83, 26);
			this->nm_speed_vert->TabIndex = 104;
			this->nm_speed_vert->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_vert_ValueChanged);
			// 
			// nm_speed_vert_pot
			// 
			this->nm_speed_vert_pot->Location = System::Drawing::Point(561, 188);
			this->nm_speed_vert_pot->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_vert_pot->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_vert_pot->Name = L"nm_speed_vert_pot";
			this->nm_speed_vert_pot->Size = System::Drawing::Size(83, 26);
			this->nm_speed_vert_pot->TabIndex = 103;
			this->nm_speed_vert_pot->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_vert_pot_ValueChanged);
			// 
			// nm_v_north
			// 
			this->nm_v_north->Location = System::Drawing::Point(561, 233);
			this->nm_v_north->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_v_north->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_v_north->Name = L"nm_v_north";
			this->nm_v_north->Size = System::Drawing::Size(83, 26);
			this->nm_v_north->TabIndex = 102;
			this->nm_v_north->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_v_north_ValueChanged);
			// 
			// nm_v_east
			// 
			this->nm_v_east->Location = System::Drawing::Point(561, 278);
			this->nm_v_east->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_v_east->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_v_east->Name = L"nm_v_east";
			this->nm_v_east->Size = System::Drawing::Size(83, 26);
			this->nm_v_east->TabIndex = 101;
			this->nm_v_east->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_v_east_ValueChanged);
			// 
			// nm_speed_track
			// 
			this->nm_speed_track->Location = System::Drawing::Point(561, 323);
			this->nm_speed_track->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_track->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_track->Name = L"nm_speed_track";
			this->nm_speed_track->Size = System::Drawing::Size(83, 26);
			this->nm_speed_track->TabIndex = 100;
			this->nm_speed_track->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_track_ValueChanged);
			// 
			// nm_a_course
			// 
			this->nm_a_course->Location = System::Drawing::Point(561, 368);
			this->nm_a_course->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_a_course->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_a_course->Name = L"nm_a_course";
			this->nm_a_course->Size = System::Drawing::Size(83, 26);
			this->nm_a_course->TabIndex = 99;
			this->nm_a_course->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_a_course_ValueChanged);
			// 
			// nm_a_vert
			// 
			this->nm_a_vert->Location = System::Drawing::Point(561, 98);
			this->nm_a_vert->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_a_vert->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_a_vert->Name = L"nm_a_vert";
			this->nm_a_vert->Size = System::Drawing::Size(83, 26);
			this->nm_a_vert->TabIndex = 98;
			this->nm_a_vert->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_a_vert_ValueChanged);
			// 
			// nm_H_otn
			// 
			this->nm_H_otn->Location = System::Drawing::Point(220, 593);
			this->nm_H_otn->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_H_otn->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_H_otn->Name = L"nm_H_otn";
			this->nm_H_otn->Size = System::Drawing::Size(83, 26);
			this->nm_H_otn->TabIndex = 97;
			this->nm_H_otn->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_H_otn_ValueChanged);
			// 
			// nm_H_cmplx
			// 
			this->nm_H_cmplx->Location = System::Drawing::Point(220, 548);
			this->nm_H_cmplx->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_H_cmplx->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_H_cmplx->Name = L"nm_H_cmplx";
			this->nm_H_cmplx->Size = System::Drawing::Size(83, 26);
			this->nm_H_cmplx->TabIndex = 96;
			this->nm_H_cmplx->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_H_cmplx_ValueChanged);
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(349, 464);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(92, 20);
			this->label24->TabIndex = 95;
			this->label24->Text = L"Угол сноса";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(349, 415);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(205, 20);
			this->label23->TabIndex = 94;
			this->label23->Text = L"Угол наклона траектории";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(349, 360);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(157, 40);
			this->label22->TabIndex = 93;
			this->label22->Text = L"Ускорение вдоль\r\nтраектории полёта";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(349, 325);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(146, 20);
			this->label21->TabIndex = 92;
			this->label21->Text = L"Путевая скорость";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(349, 280);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(180, 20);
			this->label20->TabIndex = 91;
			this->label20->Text = L"Путевая скорость E/W";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(349, 239);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(176, 20);
			this->label19->TabIndex = 90;
			this->label19->Text = L"Путевая скорость N/S";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(349, 180);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(190, 40);
			this->label18->TabIndex = 89;
			this->label18->Text = L"Потенциальная \r\nвертикальная скорость";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(349, 148);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(192, 20);
			this->label17->TabIndex = 88;
			this->label17->Text = L"Вертикальная скорость";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(349, 104);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(200, 20);
			this->label16->TabIndex = 87;
			this->label16->Text = L"Вертикальное ускорение";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(8, 546);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(169, 40);
			this->label15->TabIndex = 86;
			this->label15->Text = L"Комплексная высота\r\nполёта";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(349, 52);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(214, 20);
			this->label14->TabIndex = 85;
			this->label14->Text = L"Долгота, град., вост. долг.";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(349, 11);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(188, 20);
			this->label13->TabIndex = 84;
			this->label13->Text = L"Широта, град. сев. шир.";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(8, 506);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(186, 20);
			this->label12->TabIndex = 83;
			this->label12->Text = L"Нормальное ускорение";
			// 
			// nm_n_y
			// 
			this->nm_n_y->DecimalPlaces = 1;
			this->nm_n_y->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nm_n_y->Location = System::Drawing::Point(220, 504);
			this->nm_n_y->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_n_y->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_n_y->Name = L"nm_n_y";
			this->nm_n_y->Size = System::Drawing::Size(83, 26);
			this->nm_n_y->TabIndex = 82;
			this->nm_n_y->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_n_y_ValueChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(8, 240);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(176, 20);
			this->label11->TabIndex = 81;
			this->label11->Text = L"Гироскопический курс";
			// 
			// nm_course_gyro
			// 
			this->nm_course_gyro->Location = System::Drawing::Point(220, 234);
			this->nm_course_gyro->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_course_gyro->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_course_gyro->Name = L"nm_course_gyro";
			this->nm_course_gyro->Size = System::Drawing::Size(83, 26);
			this->nm_course_gyro->TabIndex = 80;
			this->nm_course_gyro->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_course_gyro_ValueChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(8, 275);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(149, 40);
			this->label10->TabIndex = 79;
			this->label10->Text = L"Угловая скорость \r\nтангажа";
			// 
			// nm_w_x
			// 
			this->nm_w_x->Location = System::Drawing::Point(220, 279);
			this->nm_w_x->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_w_x->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_w_x->Name = L"nm_w_x";
			this->nm_w_x->Size = System::Drawing::Size(83, 26);
			this->nm_w_x->TabIndex = 78;
			this->nm_w_x->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_w_x_ValueChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(8, 320);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(149, 40);
			this->label9->TabIndex = 77;
			this->label9->Text = L"Угловая скорость \r\nкрена";
			// 
			// nm_w_y
			// 
			this->nm_w_y->Location = System::Drawing::Point(220, 324);
			this->nm_w_y->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_w_y->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_w_y->Name = L"nm_w_y";
			this->nm_w_y->Size = System::Drawing::Size(83, 26);
			this->nm_w_y->TabIndex = 76;
			this->nm_w_y->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_w_y_ValueChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 365);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(145, 40);
			this->label8->TabIndex = 75;
			this->label8->Text = L"Угловая скорость\r\nрысканья";
			// 
			// nm_w_z
			// 
			this->nm_w_z->Location = System::Drawing::Point(220, 369);
			this->nm_w_z->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_w_z->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_w_z->Name = L"nm_w_z";
			this->nm_w_z->Size = System::Drawing::Size(83, 26);
			this->nm_w_z->TabIndex = 74;
			this->nm_w_z->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_w_z_ValueChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(8, 417);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(186, 20);
			this->label7->TabIndex = 73;
			this->label7->Text = L"Продольное ускорение";
			// 
			// nm_n_x
			// 
			this->nm_n_x->DecimalPlaces = 1;
			this->nm_n_x->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nm_n_x->Location = System::Drawing::Point(220, 414);
			this->nm_n_x->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_n_x->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_n_x->Name = L"nm_n_x";
			this->nm_n_x->Size = System::Drawing::Size(83, 26);
			this->nm_n_x->TabIndex = 72;
			this->nm_n_x->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_n_x_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 460);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(183, 20);
			this->label6->TabIndex = 71;
			this->label6->Text = L"Поперечное ускорение";
			// 
			// nm_n_z
			// 
			this->nm_n_z->DecimalPlaces = 2;
			this->nm_n_z->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->nm_n_z->Location = System::Drawing::Point(220, 459);
			this->nm_n_z->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_n_z->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_n_z->Name = L"nm_n_z";
			this->nm_n_z->Size = System::Drawing::Size(83, 26);
			this->nm_n_z->TabIndex = 70;
			this->nm_n_z->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_n_z_ValueChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 194);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(120, 20);
			this->label5->TabIndex = 69;
			this->label5->Text = L"Истинный курс";
			// 
			// nm_course_true
			// 
			this->nm_course_true->Location = System::Drawing::Point(220, 189);
			this->nm_course_true->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_course_true->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_course_true->Name = L"nm_course_true";
			this->nm_course_true->Size = System::Drawing::Size(83, 26);
			this->nm_course_true->TabIndex = 68;
			this->nm_course_true->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_course_true_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 140);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(163, 40);
			this->label4->TabIndex = 67;
			this->label4->Text = L"Магнитный путевой \r\nугол";
			// 
			// nm_course_track_mag
			// 
			this->nm_course_track_mag->Location = System::Drawing::Point(220, 144);
			this->nm_course_track_mag->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_course_track_mag->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_course_track_mag->Name = L"nm_course_track_mag";
			this->nm_course_track_mag->Size = System::Drawing::Size(83, 26);
			this->nm_course_track_mag->TabIndex = 66;
			this->nm_course_track_mag->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_course_track_mag_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 102);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(130, 20);
			this->label3->TabIndex = 65;
			this->label3->Text = L"Курс магнитный";
			// 
			// nm_course_mag
			// 
			this->nm_course_mag->Location = System::Drawing::Point(220, 99);
			this->nm_course_mag->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_course_mag->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_course_mag->Name = L"nm_course_mag";
			this->nm_course_mag->Size = System::Drawing::Size(83, 26);
			this->nm_course_mag->TabIndex = 64;
			this->nm_course_mag->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_course_mag_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(93, 20);
			this->label2->TabIndex = 63;
			this->label2->Text = L"Угол крена";
			// 
			// nm_roll
			// 
			this->nm_roll->Location = System::Drawing::Point(220, 54);
			this->nm_roll->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_roll->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_roll->Name = L"nm_roll";
			this->nm_roll->Size = System::Drawing::Size(83, 26);
			this->nm_roll->TabIndex = 62;
			this->nm_roll->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_roll_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 20);
			this->label1->TabIndex = 61;
			this->label1->Text = L"Угол тангажа";
			// 
			// nm_pitch
			// 
			this->nm_pitch->Location = System::Drawing::Point(220, 9);
			this->nm_pitch->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_pitch->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_pitch->Name = L"nm_pitch";
			this->nm_pitch->Size = System::Drawing::Size(83, 26);
			this->nm_pitch->TabIndex = 60;
			this->nm_pitch->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_pitch_ValueChanged);
			// 
			// SVS
			// 
			this->SVS->Controls->Add(this->label38);
			this->SVS->Controls->Add(this->nm_radio_altitude);
			this->SVS->Controls->Add(this->label39);
			this->SVS->Controls->Add(this->nm_altitude_trend);
			this->SVS->Controls->Add(this->label40);
			this->SVS->Controls->Add(this->nm_speed_trend);
			this->SVS->Controls->Add(this->label42);
			this->SVS->Controls->Add(this->nm_altitude_danger);
			this->SVS->Controls->Add(this->label43);
			this->SVS->Controls->Add(this->nm_Td2);
			this->SVS->Controls->Add(this->label44);
			this->SVS->Controls->Add(this->nm_Td1);
			this->SVS->Controls->Add(this->label45);
			this->SVS->Controls->Add(this->nm_P_h_stat);
			this->SVS->Controls->Add(this->label46);
			this->SVS->Controls->Add(this->nm_P_f);
			this->SVS->Controls->Add(this->label28);
			this->SVS->Controls->Add(this->nm_speed_vert_svs);
			this->SVS->Controls->Add(this->label29);
			this->SVS->Controls->Add(this->nm_M);
			this->SVS->Controls->Add(this->label30);
			this->SVS->Controls->Add(this->nm_temp_h);
			this->SVS->Controls->Add(this->label31);
			this->SVS->Controls->Add(this->nm_temp_r);
			this->SVS->Controls->Add(this->label32);
			this->SVS->Controls->Add(this->nm_Q);
			this->SVS->Controls->Add(this->label33);
			this->SVS->Controls->Add(this->nm_airspeed_prib);
			this->SVS->Controls->Add(this->label34);
			this->SVS->Controls->Add(this->nm_airspeed_true);
			this->SVS->Controls->Add(this->label35);
			this->SVS->Controls->Add(this->nm_H_qfe);
			this->SVS->Controls->Add(this->label36);
			this->SVS->Controls->Add(this->nm_H_qnh);
			this->SVS->Controls->Add(this->label37);
			this->SVS->Controls->Add(this->nm_H_abs);
			this->SVS->Location = System::Drawing::Point(4, 32);
			this->SVS->Name = L"SVS";
			this->SVS->Size = System::Drawing::Size(771, 775);
			this->SVS->TabIndex = 3;
			this->SVS->Text = L"СВС";
			this->SVS->UseVisualStyleBackColor = true;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(378, 241);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(233, 20);
			this->label38->TabIndex = 119;
			this->label38->Text = L"Высота от Радиовысотомера";
			// 
			// nm_radio_altitude
			// 
			this->nm_radio_altitude->Location = System::Drawing::Point(617, 235);
			this->nm_radio_altitude->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_radio_altitude->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_radio_altitude->Name = L"nm_radio_altitude";
			this->nm_radio_altitude->Size = System::Drawing::Size(83, 26);
			this->nm_radio_altitude->TabIndex = 118;
			this->nm_radio_altitude->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_radio_altitude_ValueChanged);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(378, 276);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(159, 20);
			this->label39->TabIndex = 117;
			this->label39->Text = L"Тренд высоты Habs";
			// 
			// nm_altitude_trend
			// 
			this->nm_altitude_trend->Location = System::Drawing::Point(617, 280);
			this->nm_altitude_trend->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_altitude_trend->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_altitude_trend->Name = L"nm_altitude_trend";
			this->nm_altitude_trend->Size = System::Drawing::Size(83, 26);
			this->nm_altitude_trend->TabIndex = 116;
			this->nm_altitude_trend->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_altitude_trend_ValueChanged);
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(378, 321);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(133, 40);
			this->label40->TabIndex = 115;
			this->label40->Text = L"Тренд скорости \r\nприборной ";
			// 
			// nm_speed_trend
			// 
			this->nm_speed_trend->Location = System::Drawing::Point(617, 325);
			this->nm_speed_trend->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_trend->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_trend->Name = L"nm_speed_trend";
			this->nm_speed_trend->Size = System::Drawing::Size(83, 26);
			this->nm_speed_trend->TabIndex = 114;
			this->nm_speed_trend->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_trend_ValueChanged);
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(378, 195);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(133, 20);
			this->label42->TabIndex = 111;
			this->label42->Text = L"Опасная высота";
			// 
			// nm_altitude_danger
			// 
			this->nm_altitude_danger->Location = System::Drawing::Point(617, 190);
			this->nm_altitude_danger->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_altitude_danger->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_altitude_danger->Name = L"nm_altitude_danger";
			this->nm_altitude_danger->Size = System::Drawing::Size(83, 26);
			this->nm_altitude_danger->TabIndex = 110;
			this->nm_altitude_danger->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_altitude_danger_ValueChanged);
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(378, 141);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(180, 40);
			this->label43->TabIndex = 109;
			this->label43->Text = L"Температура датчика \r\nдавления воздуха Д2 ";
			// 
			// nm_Td2
			// 
			this->nm_Td2->Location = System::Drawing::Point(617, 145);
			this->nm_Td2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_Td2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_Td2->Name = L"nm_Td2";
			this->nm_Td2->Size = System::Drawing::Size(83, 26);
			this->nm_Td2->TabIndex = 108;
			this->nm_Td2->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_Td2_ValueChanged);
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(378, 92);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(180, 40);
			this->label44->TabIndex = 107;
			this->label44->Text = L"Температура датчика \r\nдавления воздуха Д1";
			// 
			// nm_Td1
			// 
			this->nm_Td1->Location = System::Drawing::Point(617, 100);
			this->nm_Td1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_Td1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_Td1->Name = L"nm_Td1";
			this->nm_Td1->Size = System::Drawing::Size(83, 26);
			this->nm_Td1->TabIndex = 106;
			this->nm_Td1->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_Td1_ValueChanged);
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(378, 50);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(191, 40);
			this->label45->TabIndex = 105;
			this->label45->Text = L"Статическое давление \r\nвоздуха ";
			// 
			// nm_P_h_stat
			// 
			this->nm_P_h_stat->Location = System::Drawing::Point(617, 55);
			this->nm_P_h_stat->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_P_h_stat->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_P_h_stat->Name = L"nm_P_h_stat";
			this->nm_P_h_stat->Size = System::Drawing::Size(83, 26);
			this->nm_P_h_stat->TabIndex = 104;
			this->nm_P_h_stat->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_P_h_stat_ValueChanged);
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(378, 12);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(150, 20);
			this->label46->TabIndex = 103;
			this->label46->Text = L"Полное давление ";
			// 
			// nm_P_f
			// 
			this->nm_P_f->Location = System::Drawing::Point(617, 10);
			this->nm_P_f->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_P_f->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_P_f->Name = L"nm_P_f";
			this->nm_P_f->Size = System::Drawing::Size(83, 26);
			this->nm_P_f->TabIndex = 102;
			this->nm_P_f->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_P_f_ValueChanged);
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(8, 241);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(223, 20);
			this->label28->TabIndex = 101;
			this->label28->Text = L"Вертикальная скорость, м/с";
			// 
			// nm_speed_vert_svs
			// 
			this->nm_speed_vert_svs->Location = System::Drawing::Point(247, 235);
			this->nm_speed_vert_svs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_vert_svs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_vert_svs->Name = L"nm_speed_vert_svs";
			this->nm_speed_vert_svs->Size = System::Drawing::Size(83, 26);
			this->nm_speed_vert_svs->TabIndex = 100;
			this->nm_speed_vert_svs->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_vert_svs_ValueChanged);
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(8, 276);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(96, 20);
			this->label29->TabIndex = 99;
			this->label29->Text = L"число Маха";
			// 
			// nm_M
			// 
			this->nm_M->Location = System::Drawing::Point(247, 280);
			this->nm_M->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_M->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_M->Name = L"nm_M";
			this->nm_M->Size = System::Drawing::Size(83, 26);
			this->nm_M->TabIndex = 98;
			this->nm_M->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_M_ValueChanged);
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(8, 321);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(191, 40);
			this->label30->TabIndex = 97;
			this->label30->Text = L"Температура наружного\r\n воздуха";
			// 
			// nm_temp_h
			// 
			this->nm_temp_h->Location = System::Drawing::Point(247, 325);
			this->nm_temp_h->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_temp_h->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_temp_h->Name = L"nm_temp_h";
			this->nm_temp_h->Size = System::Drawing::Size(83, 26);
			this->nm_temp_h->TabIndex = 96;
			this->nm_temp_h->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_temp_h_ValueChanged);
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(8, 366);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(210, 20);
			this->label31->TabIndex = 95;
			this->label31->Text = L"Температура торможения ";
			// 
			// nm_temp_r
			// 
			this->nm_temp_r->Location = System::Drawing::Point(247, 370);
			this->nm_temp_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_temp_r->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_temp_r->Name = L"nm_temp_r";
			this->nm_temp_r->Size = System::Drawing::Size(83, 26);
			this->nm_temp_r->TabIndex = 94;
			this->nm_temp_r->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_temp_r_ValueChanged);
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(378, 376);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(152, 20);
			this->label32->TabIndex = 93;
			this->label32->Text = L"Скоростной напор ";
			// 
			// nm_Q
			// 
			this->nm_Q->Location = System::Drawing::Point(617, 373);
			this->nm_Q->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_Q->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_Q->Name = L"nm_Q";
			this->nm_Q->Size = System::Drawing::Size(83, 26);
			this->nm_Q->TabIndex = 92;
			this->nm_Q->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_Q_ValueChanged);
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(8, 195);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(206, 20);
			this->label33->TabIndex = 91;
			this->label33->Text = L"Приборная скорость, км/ч";
			// 
			// nm_airspeed_prib
			// 
			this->nm_airspeed_prib->Location = System::Drawing::Point(247, 190);
			this->nm_airspeed_prib->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_airspeed_prib->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_airspeed_prib->Name = L"nm_airspeed_prib";
			this->nm_airspeed_prib->Size = System::Drawing::Size(83, 26);
			this->nm_airspeed_prib->TabIndex = 90;
			this->nm_airspeed_prib->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_airspeed_prib_ValueChanged);
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(8, 141);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(184, 40);
			this->label34->TabIndex = 89;
			this->label34->Text = L"Истинная (воздушная) \r\nскорость, км/ч";
			// 
			// nm_airspeed_true
			// 
			this->nm_airspeed_true->Location = System::Drawing::Point(247, 145);
			this->nm_airspeed_true->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_airspeed_true->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_airspeed_true->Name = L"nm_airspeed_true";
			this->nm_airspeed_true->Size = System::Drawing::Size(83, 26);
			this->nm_airspeed_true->TabIndex = 88;
			this->nm_airspeed_true->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_airspeed_true_ValueChanged);
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(8, 92);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(228, 40);
			this->label35->TabIndex = 87;
			this->label35->Text = L"Относительная баровысота \r\n(коррекция по QFE)";
			// 
			// nm_H_qfe
			// 
			this->nm_H_qfe->Location = System::Drawing::Point(247, 100);
			this->nm_H_qfe->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_H_qfe->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_H_qfe->Name = L"nm_H_qfe";
			this->nm_H_qfe->Size = System::Drawing::Size(83, 26);
			this->nm_H_qfe->TabIndex = 86;
			this->nm_H_qfe->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_H_qfe_ValueChanged);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(8, 50);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(228, 40);
			this->label36->TabIndex = 85;
			this->label36->Text = L"Относительная баровысота \r\n(коррекция по QNH)";
			// 
			// nm_H_qnh
			// 
			this->nm_H_qnh->Location = System::Drawing::Point(247, 55);
			this->nm_H_qnh->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_H_qnh->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_H_qnh->Name = L"nm_H_qnh";
			this->nm_H_qnh->Size = System::Drawing::Size(83, 26);
			this->nm_H_qnh->TabIndex = 84;
			this->nm_H_qnh->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_H_qnh_ValueChanged);
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(8, 4);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(203, 40);
			this->label37->TabIndex = 83;
			this->label37->Text = L"Абсолютная \r\nбарометрическая высота";
			// 
			// nm_H_abs
			// 
			this->nm_H_abs->Location = System::Drawing::Point(247, 10);
			this->nm_H_abs->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_H_abs->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_H_abs->Name = L"nm_H_abs";
			this->nm_H_abs->Size = System::Drawing::Size(83, 26);
			this->nm_H_abs->TabIndex = 82;
			this->nm_H_abs->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_H_abs_ValueChanged);
			// 
			// SNS
			// 
			this->SNS->Controls->Add(this->nm_L_clx_sns);
			this->SNS->Controls->Add(this->nm_B_clx_sns);
			this->SNS->Controls->Add(this->cb_baro_update);
			this->SNS->Controls->Add(this->rb_QNE);
			this->SNS->Controls->Add(this->rb_QNH);
			this->SNS->Controls->Add(this->rb_QFE);
			this->SNS->Controls->Add(this->label59);
			this->SNS->Controls->Add(this->label56);
			this->SNS->Controls->Add(this->nm_H_sns);
			this->SNS->Controls->Add(this->label55);
			this->SNS->Controls->Add(this->nm_track_angle_sns);
			this->SNS->Controls->Add(this->label41);
			this->SNS->Controls->Add(this->nm_vertical_speed_sns);
			this->SNS->Controls->Add(this->label47);
			this->SNS->Controls->Add(this->nm_speed_track_sns);
			this->SNS->Controls->Add(this->label48);
			this->SNS->Controls->Add(this->nm_v_north_sns);
			this->SNS->Controls->Add(this->label49);
			this->SNS->Controls->Add(this->nm_v_east_sns);
			this->SNS->Controls->Add(this->label50);
			this->SNS->Controls->Add(this->nm_pdop);
			this->SNS->Controls->Add(this->label51);
			this->SNS->Controls->Add(this->nm_vdop);
			this->SNS->Controls->Add(this->label52);
			this->SNS->Controls->Add(this->nm_hdop);
			this->SNS->Controls->Add(this->label53);
			this->SNS->Controls->Add(this->label54);
			this->SNS->Location = System::Drawing::Point(4, 32);
			this->SNS->Name = L"SNS";
			this->SNS->Size = System::Drawing::Size(771, 775);
			this->SNS->TabIndex = 4;
			this->SNS->Text = L"СНС";
			this->SNS->UseVisualStyleBackColor = true;
			// 
			// nm_L_clx_sns
			// 
			this->nm_L_clx_sns->DecimalPlaces = 6;
			this->nm_L_clx_sns->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nm_L_clx_sns->Location = System::Drawing::Point(249, 55);
			this->nm_L_clx_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			this->nm_L_clx_sns->Name = L"nm_L_clx_sns";
			this->nm_L_clx_sns->Size = System::Drawing::Size(137, 26);
			this->nm_L_clx_sns->TabIndex = 130;
			this->nm_L_clx_sns->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 83010267, 0, 0, 393216 });
			this->nm_L_clx_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_L_clx_sns_ValueChanged);
			// 
			// nm_B_clx_sns
			// 
			this->nm_B_clx_sns->DecimalPlaces = 6;
			this->nm_B_clx_sns->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nm_B_clx_sns->Location = System::Drawing::Point(249, 10);
			this->nm_B_clx_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 180, 0, 0, 0 });
			this->nm_B_clx_sns->Name = L"nm_B_clx_sns";
			this->nm_B_clx_sns->Size = System::Drawing::Size(137, 26);
			this->nm_B_clx_sns->TabIndex = 129;
			this->nm_B_clx_sns->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 55104799, 0, 0, 393216 });
			this->nm_B_clx_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_B_clx_sns_ValueChanged);
			// 
			// cb_baro_update
			// 
			this->cb_baro_update->AutoSize = true;
			this->cb_baro_update->BackColor = System::Drawing::Color::Transparent;
			this->cb_baro_update->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_baro_update->Location = System::Drawing::Point(425, 153);
			this->cb_baro_update->Name = L"cb_baro_update";
			this->cb_baro_update->Size = System::Drawing::Size(255, 44);
			this->cb_baro_update->TabIndex = 128;
			this->cb_baro_update->Text = L"Признак \"Данные коррекции \r\nбаровысоты обновлены\"";
			this->cb_baro_update->UseVisualStyleBackColor = false;
			this->cb_baro_update->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_baro_update_CheckedChanged);
			// 
			// rb_QNE
			// 
			this->rb_QNE->AutoSize = true;
			this->rb_QNE->Location = System::Drawing::Point(660, 112);
			this->rb_QNE->Name = L"rb_QNE";
			this->rb_QNE->Size = System::Drawing::Size(68, 24);
			this->rb_QNE->TabIndex = 127;
			this->rb_QNE->Text = L"QNE";
			this->rb_QNE->UseVisualStyleBackColor = true;
			this->rb_QNE->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_QNE_CheckedChanged);
			// 
			// rb_QNH
			// 
			this->rb_QNH->AutoSize = true;
			this->rb_QNH->Location = System::Drawing::Point(660, 82);
			this->rb_QNH->Name = L"rb_QNH";
			this->rb_QNH->Size = System::Drawing::Size(69, 24);
			this->rb_QNH->TabIndex = 126;
			this->rb_QNH->Text = L"QNH";
			this->rb_QNH->UseVisualStyleBackColor = true;
			this->rb_QNH->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_QNH_CheckedChanged);
			// 
			// rb_QFE
			// 
			this->rb_QFE->AutoSize = true;
			this->rb_QFE->Checked = true;
			this->rb_QFE->Location = System::Drawing::Point(660, 52);
			this->rb_QFE->Name = L"rb_QFE";
			this->rb_QFE->Size = System::Drawing::Size(67, 24);
			this->rb_QFE->TabIndex = 125;
			this->rb_QFE->TabStop = true;
			this->rb_QFE->Text = L"QFE";
			this->rb_QFE->UseVisualStyleBackColor = true;
			this->rb_QFE->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rb_QFE_CheckedChanged);
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(421, 66);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(156, 40);
			this->label59->TabIndex = 124;
			this->label59->Text = L"Текущая коррекция\r\nбаровысоты";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(421, 12);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(104, 20);
			this->label56->TabIndex = 123;
			this->label56->Text = L"Высота СНС";
			// 
			// nm_H_sns
			// 
			this->nm_H_sns->Location = System::Drawing::Point(660, 10);
			this->nm_H_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_H_sns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_H_sns->Name = L"nm_H_sns";
			this->nm_H_sns->Size = System::Drawing::Size(83, 26);
			this->nm_H_sns->TabIndex = 122;
			this->nm_H_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_H_sns_ValueChanged);
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(8, 412);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(187, 20);
			this->label55->TabIndex = 121;
			this->label55->Text = L"Путевой угол истинный";
			// 
			// nm_track_angle_sns
			// 
			this->nm_track_angle_sns->Location = System::Drawing::Point(247, 410);
			this->nm_track_angle_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_track_angle_sns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_track_angle_sns->Name = L"nm_track_angle_sns";
			this->nm_track_angle_sns->Size = System::Drawing::Size(83, 26);
			this->nm_track_angle_sns->TabIndex = 120;
			this->nm_track_angle_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_track_angle_sns_ValueChanged);
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(8, 230);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(126, 40);
			this->label41->TabIndex = 119;
			this->label41->Text = L"Вертикальная \r\nскорость (СНС)";
			// 
			// nm_vertical_speed_sns
			// 
			this->nm_vertical_speed_sns->Location = System::Drawing::Point(247, 235);
			this->nm_vertical_speed_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_vertical_speed_sns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_vertical_speed_sns->Name = L"nm_vertical_speed_sns";
			this->nm_vertical_speed_sns->Size = System::Drawing::Size(83, 26);
			this->nm_vertical_speed_sns->TabIndex = 118;
			this->nm_vertical_speed_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_vertical_speed_sns_ValueChanged);
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(8, 273);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(122, 40);
			this->label47->TabIndex = 117;
			this->label47->Text = L"Путевая \r\nскорость(СНС)";
			// 
			// nm_speed_track_sns
			// 
			this->nm_speed_track_sns->Location = System::Drawing::Point(247, 280);
			this->nm_speed_track_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_track_sns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_track_sns->Name = L"nm_speed_track_sns";
			this->nm_speed_track_sns->Size = System::Drawing::Size(83, 26);
			this->nm_speed_track_sns->TabIndex = 116;
			this->nm_speed_track_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_track_sns_ValueChanged);
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(8, 327);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(176, 20);
			this->label48->TabIndex = 115;
			this->label48->Text = L"Путевая скорость N/S";
			// 
			// nm_v_north_sns
			// 
			this->nm_v_north_sns->Location = System::Drawing::Point(247, 325);
			this->nm_v_north_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_v_north_sns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_v_north_sns->Name = L"nm_v_north_sns";
			this->nm_v_north_sns->Size = System::Drawing::Size(83, 26);
			this->nm_v_north_sns->TabIndex = 114;
			this->nm_v_north_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_v_north_sns_ValueChanged);
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(8, 372);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(180, 20);
			this->label49->TabIndex = 113;
			this->label49->Text = L"Путевая скорость E/W";
			// 
			// nm_v_east_sns
			// 
			this->nm_v_east_sns->Location = System::Drawing::Point(247, 370);
			this->nm_v_east_sns->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_v_east_sns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_v_east_sns->Name = L"nm_v_east_sns";
			this->nm_v_east_sns->Size = System::Drawing::Size(83, 26);
			this->nm_v_east_sns->TabIndex = 112;
			this->nm_v_east_sns->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_v_east_sns_ValueChanged);
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(8, 184);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(233, 40);
			this->label50->TabIndex = 111;
			this->label50->Text = L"Показатель ухудшения \r\nвертикальной точности Pdop";
			// 
			// nm_pdop
			// 
			this->nm_pdop->Location = System::Drawing::Point(247, 190);
			this->nm_pdop->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_pdop->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_pdop->Name = L"nm_pdop";
			this->nm_pdop->Size = System::Drawing::Size(83, 26);
			this->nm_pdop->TabIndex = 110;
			this->nm_pdop->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_pdop_ValueChanged);
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(8, 138);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(196, 40);
			this->label51->TabIndex = 109;
			this->label51->Text = L"Показатель ухудшения \r\nвертикальной точности ";
			// 
			// nm_vdop
			// 
			this->nm_vdop->Location = System::Drawing::Point(247, 145);
			this->nm_vdop->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_vdop->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_vdop->Name = L"nm_vdop";
			this->nm_vdop->Size = System::Drawing::Size(83, 26);
			this->nm_vdop->TabIndex = 107;
			this->nm_vdop->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_vdop_ValueChanged);
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(8, 92);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(208, 40);
			this->label52->TabIndex = 107;
			this->label52->Text = L"Показатель ухудшения \r\nгоризонтальной точности";
			// 
			// nm_hdop
			// 
			this->nm_hdop->Location = System::Drawing::Point(247, 100);
			this->nm_hdop->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_hdop->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_hdop->Name = L"nm_hdop";
			this->nm_hdop->Size = System::Drawing::Size(83, 26);
			this->nm_hdop->TabIndex = 106;
			this->nm_hdop->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_hdop_ValueChanged);
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(8, 57);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(205, 20);
			this->label53->TabIndex = 105;
			this->label53->Text = L"Географическая долгота";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(8, 12);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(199, 20);
			this->label54->TabIndex = 103;
			this->label54->Text = L"Географическая широта";
			// 
			// RC
			// 
			this->RC->Controls->Add(this->cb_apu_work);
			this->RC->Controls->Add(this->cb_apu_start);
			this->RC->Controls->Add(this->cb_wow);
			this->RC->Controls->Add(this->cb_manual_mode);
			this->RC->Controls->Add(this->cb_engine_start);
			this->RC->Controls->Add(this->cb_rudder_trim_n);
			this->RC->Controls->Add(this->cb_elevator_trim_n);
			this->RC->Controls->Add(this->cb_ailerons_trim_n);
			this->RC->Location = System::Drawing::Point(4, 32);
			this->RC->Name = L"RC";
			this->RC->Size = System::Drawing::Size(771, 775);
			this->RC->TabIndex = 5;
			this->RC->Text = L"РК";
			this->RC->UseVisualStyleBackColor = true;
			// 
			// cb_apu_work
			// 
			this->cb_apu_work->AutoSize = true;
			this->cb_apu_work->BackColor = System::Drawing::Color::Transparent;
			this->cb_apu_work->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_apu_work->Location = System::Drawing::Point(8, 217);
			this->cb_apu_work->Name = L"cb_apu_work";
			this->cb_apu_work->Size = System::Drawing::Size(126, 24);
			this->cb_apu_work->TabIndex = 130;
			this->cb_apu_work->Text = L"ВСУ Работа";
			this->cb_apu_work->UseVisualStyleBackColor = false;
			this->cb_apu_work->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_apu_work_CheckedChanged);
			// 
			// cb_apu_start
			// 
			this->cb_apu_start->AutoSize = true;
			this->cb_apu_start->BackColor = System::Drawing::Color::Transparent;
			this->cb_apu_start->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_apu_start->Location = System::Drawing::Point(7, 187);
			this->cb_apu_start->Name = L"cb_apu_start";
			this->cb_apu_start->Size = System::Drawing::Size(123, 24);
			this->cb_apu_start->TabIndex = 130;
			this->cb_apu_start->Text = L"ВСУ Запуск";
			this->cb_apu_start->UseVisualStyleBackColor = false;
			this->cb_apu_start->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_apu_start_CheckedChanged);
			// 
			// cb_wow
			// 
			this->cb_wow->AutoSize = true;
			this->cb_wow->BackColor = System::Drawing::Color::Transparent;
			this->cb_wow->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_wow->Location = System::Drawing::Point(8, 157);
			this->cb_wow->Name = L"cb_wow";
			this->cb_wow->Size = System::Drawing::Size(142, 24);
			this->cb_wow->TabIndex = 130;
			this->cb_wow->Text = L"Шасси обжато";
			this->cb_wow->UseVisualStyleBackColor = false;
			this->cb_wow->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_wow_CheckedChanged);
			// 
			// cb_manual_mode
			// 
			this->cb_manual_mode->AutoSize = true;
			this->cb_manual_mode->BackColor = System::Drawing::Color::Transparent;
			this->cb_manual_mode->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_manual_mode->Location = System::Drawing::Point(8, 127);
			this->cb_manual_mode->Name = L"cb_manual_mode";
			this->cb_manual_mode->Size = System::Drawing::Size(141, 24);
			this->cb_manual_mode->TabIndex = 130;
			this->cb_manual_mode->Text = L"Ручной режим";
			this->cb_manual_mode->UseVisualStyleBackColor = false;
			this->cb_manual_mode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_manual_mode_CheckedChanged);
			// 
			// cb_engine_start
			// 
			this->cb_engine_start->AutoSize = true;
			this->cb_engine_start->BackColor = System::Drawing::Color::Transparent;
			this->cb_engine_start->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_engine_start->Location = System::Drawing::Point(8, 97);
			this->cb_engine_start->Name = L"cb_engine_start";
			this->cb_engine_start->Size = System::Drawing::Size(173, 24);
			this->cb_engine_start->TabIndex = 130;
			this->cb_engine_start->Text = L"Запуск двигателя";
			this->cb_engine_start->UseVisualStyleBackColor = false;
			this->cb_engine_start->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_engine_start_CheckedChanged);
			// 
			// cb_rudder_trim_n
			// 
			this->cb_rudder_trim_n->AutoSize = true;
			this->cb_rudder_trim_n->BackColor = System::Drawing::Color::Transparent;
			this->cb_rudder_trim_n->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_rudder_trim_n->Location = System::Drawing::Point(8, 67);
			this->cb_rudder_trim_n->Name = L"cb_rudder_trim_n";
			this->cb_rudder_trim_n->Size = System::Drawing::Size(332, 24);
			this->cb_rudder_trim_n->TabIndex = 130;
			this->cb_rudder_trim_n->Text = L"Нейтральное положение триммера РН";
			this->cb_rudder_trim_n->UseVisualStyleBackColor = false;
			this->cb_rudder_trim_n->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_rudder_trim_n_CheckedChanged);
			// 
			// cb_elevator_trim_n
			// 
			this->cb_elevator_trim_n->AutoSize = true;
			this->cb_elevator_trim_n->BackColor = System::Drawing::Color::Transparent;
			this->cb_elevator_trim_n->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_elevator_trim_n->Location = System::Drawing::Point(8, 37);
			this->cb_elevator_trim_n->Name = L"cb_elevator_trim_n";
			this->cb_elevator_trim_n->Size = System::Drawing::Size(331, 24);
			this->cb_elevator_trim_n->TabIndex = 130;
			this->cb_elevator_trim_n->Text = L"Нейтральное положение триммера РВ";
			this->cb_elevator_trim_n->UseVisualStyleBackColor = false;
			this->cb_elevator_trim_n->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_elevator_trim_n_CheckedChanged);
			// 
			// cb_ailerons_trim_n
			// 
			this->cb_ailerons_trim_n->AutoSize = true;
			this->cb_ailerons_trim_n->BackColor = System::Drawing::Color::Transparent;
			this->cb_ailerons_trim_n->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->cb_ailerons_trim_n->Location = System::Drawing::Point(8, 7);
			this->cb_ailerons_trim_n->Name = L"cb_ailerons_trim_n";
			this->cb_ailerons_trim_n->Size = System::Drawing::Size(383, 24);
			this->cb_ailerons_trim_n->TabIndex = 129;
			this->cb_ailerons_trim_n->Text = L"Нейтральное положение триммера элеронов";
			this->cb_ailerons_trim_n->UseVisualStyleBackColor = false;
			this->cb_ailerons_trim_n->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cb_ailerons_trim_n_CheckedChanged);
			// 
			// Params
			// 
			this->Params->AutoScroll = true;
			this->Params->Controls->Add(this->label68);
			this->Params->Controls->Add(this->label87);
			this->Params->Controls->Add(this->label85);
			this->Params->Controls->Add(this->label86);
			this->Params->Controls->Add(this->label84);
			this->Params->Controls->Add(this->label83);
			this->Params->Controls->Add(this->label82);
			this->Params->Controls->Add(this->label81);
			this->Params->Controls->Add(this->nm_speed_max);
			this->Params->Controls->Add(this->label80);
			this->Params->Controls->Add(this->nm_ny_max);
			this->Params->Controls->Add(this->label79);
			this->Params->Controls->Add(this->nm_speed_min);
			this->Params->Controls->Add(this->nm_alpha_max);
			this->Params->Controls->Add(this->nm_ny_min);
			this->Params->Controls->Add(this->label78);
			this->Params->Controls->Add(this->nm_alpha_min);
			this->Params->Controls->Add(this->label77);
			this->Params->Controls->Add(this->nm_alpha);
			this->Params->Controls->Add(this->label76);
			this->Params->Controls->Add(this->nm_oil_radiator_position);
			this->Params->Controls->Add(this->label75);
			this->Params->Controls->Add(this->nm_flaps_position);
			this->Params->Controls->Add(this->nm_engine_exhaust_temperature);
			this->Params->Controls->Add(this->label74);
			this->Params->Controls->Add(this->nm_engine_rate);
			this->Params->Controls->Add(this->label73);
			this->Params->Controls->Add(this->nm_engine_torque);
			this->Params->Controls->Add(this->label72);
			this->Params->Controls->Add(this->nm_fuel_rem_r);
			this->Params->Controls->Add(this->label71);
			this->Params->Controls->Add(this->nm_fuel_rem_l);
			this->Params->Controls->Add(this->nm_oil_temperature);
			this->Params->Controls->Add(this->label70);
			this->Params->Controls->Add(this->nm_fuel_consumption);
			this->Params->Controls->Add(this->label69);
			this->Params->Controls->Add(this->nm_fuel_pressure);
			this->Params->Controls->Add(this->label67);
			this->Params->Controls->Add(this->nm_oil_pressure);
			this->Params->Controls->Add(this->label66);
			this->Params->Controls->Add(this->nm_generator_voltage);
			this->Params->Controls->Add(this->nm_generator_current);
			this->Params->Controls->Add(this->nm_battery_voltage);
			this->Params->Controls->Add(this->nm_battery_current);
			this->Params->Controls->Add(this->label62);
			this->Params->Controls->Add(this->nm_flash_block);
			this->Params->Controls->Add(this->label61);
			this->Params->Controls->Add(this->nm_flash_page);
			this->Params->Controls->Add(this->label60);
			this->Params->Controls->Add(this->nm_pressure);
			this->Params->Location = System::Drawing::Point(4, 32);
			this->Params->Name = L"Params";
			this->Params->Size = System::Drawing::Size(771, 775);
			this->Params->TabIndex = 6;
			this->Params->Text = L"Параметры";
			this->Params->UseVisualStyleBackColor = true;
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(8, 154);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(232, 20);
			this->label68->TabIndex = 109;
			this->label68->Text = L"Ток генератора от 0 до 300 А";
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->Location = System::Drawing::Point(8, 705);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(408, 20);
			this->label87->TabIndex = 109;
			this->label87->Text = L"Скорость максимально допустимая от 0 до 400 км/ч";
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->Location = System::Drawing::Point(8, 647);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(421, 20);
			this->label85->TabIndex = 109;
			this->label85->Text = L"Перегрузка максимально допустимая от -10 до +10 гр";
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->Location = System::Drawing::Point(8, 676);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(401, 20);
			this->label86->TabIndex = 109;
			this->label86->Text = L"Скорость минимально допустимая от 0 до 400 км/ч";
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->Location = System::Drawing::Point(8, 618);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(394, 20);
			this->label84->TabIndex = 109;
			this->label84->Text = L"Перегрузка минимально допустимая от -10 до +10";
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->Location = System::Drawing::Point(8, 589);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(420, 20);
			this->label83->TabIndex = 109;
			this->label83->Text = L"Угол атаки максимально допустимый от -10 до +50 гр";
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->Location = System::Drawing::Point(8, 560);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(413, 20);
			this->label82->TabIndex = 109;
			this->label82->Text = L"Угол атаки минимально допустимый от -10 до +50 гр";
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->Location = System::Drawing::Point(8, 531);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(301, 20);
			this->label81->TabIndex = 109;
			this->label81->Text = L"Расчетный угол атаки от -10 до +50 гр";
			// 
			// nm_speed_max
			// 
			this->nm_speed_max->Location = System::Drawing::Point(511, 703);
			this->nm_speed_max->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_max->Name = L"nm_speed_max";
			this->nm_speed_max->Size = System::Drawing::Size(83, 26);
			this->nm_speed_max->TabIndex = 108;
			this->nm_speed_max->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_max_ValueChanged);
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->Location = System::Drawing::Point(8, 502);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(396, 20);
			this->label80->TabIndex = 109;
			this->label80->Text = L"Положение створки маслорадиатора от 0 до 30 гр";
			// 
			// nm_ny_max
			// 
			this->nm_ny_max->Location = System::Drawing::Point(511, 645);
			this->nm_ny_max->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_ny_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_ny_max->Name = L"nm_ny_max";
			this->nm_ny_max->Size = System::Drawing::Size(83, 26);
			this->nm_ny_max->TabIndex = 108;
			this->nm_ny_max->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_ny_max_ValueChanged);
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->Location = System::Drawing::Point(8, 473);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(282, 20);
			this->label79->TabIndex = 109;
			this->label79->Text = L"Положение закрылков от 0 до 50 гр";
			// 
			// nm_speed_min
			// 
			this->nm_speed_min->Location = System::Drawing::Point(511, 674);
			this->nm_speed_min->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_speed_min->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_speed_min->Name = L"nm_speed_min";
			this->nm_speed_min->Size = System::Drawing::Size(83, 26);
			this->nm_speed_min->TabIndex = 108;
			this->nm_speed_min->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_speed_min_ValueChanged);
			// 
			// nm_alpha_max
			// 
			this->nm_alpha_max->Location = System::Drawing::Point(511, 587);
			this->nm_alpha_max->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_alpha_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_alpha_max->Name = L"nm_alpha_max";
			this->nm_alpha_max->Size = System::Drawing::Size(83, 26);
			this->nm_alpha_max->TabIndex = 108;
			this->nm_alpha_max->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_alpha_max_ValueChanged);
			// 
			// nm_ny_min
			// 
			this->nm_ny_min->Location = System::Drawing::Point(511, 616);
			this->nm_ny_min->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_ny_min->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_ny_min->Name = L"nm_ny_min";
			this->nm_ny_min->Size = System::Drawing::Size(83, 26);
			this->nm_ny_min->TabIndex = 108;
			this->nm_ny_min->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_ny_min_ValueChanged);
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->Location = System::Drawing::Point(8, 444);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(439, 20);
			this->label78->TabIndex = 109;
			this->label78->Text = L"Температура выходящих газов двигателя от 0 до 900 гр";
			// 
			// nm_alpha_min
			// 
			this->nm_alpha_min->Location = System::Drawing::Point(511, 558);
			this->nm_alpha_min->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_alpha_min->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_alpha_min->Name = L"nm_alpha_min";
			this->nm_alpha_min->Size = System::Drawing::Size(83, 26);
			this->nm_alpha_min->TabIndex = 108;
			this->nm_alpha_min->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_alpha_min_ValueChanged);
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->Location = System::Drawing::Point(8, 415);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(353, 20);
			this->label77->TabIndex = 109;
			this->label77->Text = L"Значение оборотов двигателя от 0 до 120 %";
			// 
			// nm_alpha
			// 
			this->nm_alpha->Location = System::Drawing::Point(511, 529);
			this->nm_alpha->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_alpha->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_alpha->Name = L"nm_alpha";
			this->nm_alpha->Size = System::Drawing::Size(83, 26);
			this->nm_alpha->TabIndex = 108;
			this->nm_alpha->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_alpha_ValueChanged);
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->Location = System::Drawing::Point(8, 386);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(437, 20);
			this->label76->TabIndex = 109;
			this->label76->Text = L"Значение крутящего момента/шага винта от 0 до 120 %";
			// 
			// nm_oil_radiator_position
			// 
			this->nm_oil_radiator_position->Location = System::Drawing::Point(511, 500);
			this->nm_oil_radiator_position->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_oil_radiator_position->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_oil_radiator_position->Name = L"nm_oil_radiator_position";
			this->nm_oil_radiator_position->Size = System::Drawing::Size(83, 26);
			this->nm_oil_radiator_position->TabIndex = 108;
			this->nm_oil_radiator_position->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_oil_radiator_position_ValueChanged);
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->Location = System::Drawing::Point(8, 357);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(357, 20);
			this->label75->TabIndex = 109;
			this->label75->Text = L"Остаток топлива в правом баке от 0 до 700 л";
			// 
			// nm_flaps_position
			// 
			this->nm_flaps_position->Location = System::Drawing::Point(511, 471);
			this->nm_flaps_position->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_flaps_position->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_flaps_position->Name = L"nm_flaps_position";
			this->nm_flaps_position->Size = System::Drawing::Size(83, 26);
			this->nm_flaps_position->TabIndex = 108;
			this->nm_flaps_position->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_flaps_position_ValueChanged);
			// 
			// nm_engine_exhaust_temperature
			// 
			this->nm_engine_exhaust_temperature->Location = System::Drawing::Point(511, 442);
			this->nm_engine_exhaust_temperature->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_engine_exhaust_temperature->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_engine_exhaust_temperature->Name = L"nm_engine_exhaust_temperature";
			this->nm_engine_exhaust_temperature->Size = System::Drawing::Size(83, 26);
			this->nm_engine_exhaust_temperature->TabIndex = 108;
			this->nm_engine_exhaust_temperature->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nm_engine_exhaust_temperature->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_engine_exhaust_temperature_ValueChanged);
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Location = System::Drawing::Point(8, 328);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(349, 20);
			this->label74->TabIndex = 109;
			this->label74->Text = L"Остаток топлива в левом баке от 0 до 700 л";
			// 
			// nm_engine_rate
			// 
			this->nm_engine_rate->Location = System::Drawing::Point(511, 413);
			this->nm_engine_rate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_engine_rate->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_engine_rate->Name = L"nm_engine_rate";
			this->nm_engine_rate->Size = System::Drawing::Size(83, 26);
			this->nm_engine_rate->TabIndex = 108;
			this->nm_engine_rate->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_engine_rate_ValueChanged);
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Location = System::Drawing::Point(8, 299);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(283, 20);
			this->label73->TabIndex = 109;
			this->label73->Text = L"Температура масла от -60 до 200 гр";
			// 
			// nm_engine_torque
			// 
			this->nm_engine_torque->Location = System::Drawing::Point(511, 384);
			this->nm_engine_torque->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_engine_torque->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_engine_torque->Name = L"nm_engine_torque";
			this->nm_engine_torque->Size = System::Drawing::Size(83, 26);
			this->nm_engine_torque->TabIndex = 108;
			this->nm_engine_torque->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_engine_torque_ValueChanged);
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Location = System::Drawing::Point(8, 270);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(248, 20);
			this->label72->TabIndex = 109;
			this->label72->Text = L"Расход топлива от 0 до 300 л/ч";
			// 
			// nm_fuel_rem_r
			// 
			this->nm_fuel_rem_r->Location = System::Drawing::Point(511, 355);
			this->nm_fuel_rem_r->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_fuel_rem_r->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_fuel_rem_r->Name = L"nm_fuel_rem_r";
			this->nm_fuel_rem_r->Size = System::Drawing::Size(83, 26);
			this->nm_fuel_rem_r->TabIndex = 108;
			this->nm_fuel_rem_r->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nm_fuel_rem_r->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_fuel_rem_r_ValueChanged);
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Location = System::Drawing::Point(8, 241);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(285, 20);
			this->label71->TabIndex = 109;
			this->label71->Text = L"Давление топлива от 0 до 10 кг/см2";
			// 
			// nm_fuel_rem_l
			// 
			this->nm_fuel_rem_l->Location = System::Drawing::Point(511, 326);
			this->nm_fuel_rem_l->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_fuel_rem_l->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_fuel_rem_l->Name = L"nm_fuel_rem_l";
			this->nm_fuel_rem_l->Size = System::Drawing::Size(83, 26);
			this->nm_fuel_rem_l->TabIndex = 108;
			this->nm_fuel_rem_l->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->nm_fuel_rem_l->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_fuel_rem_l_ValueChanged);
			// 
			// nm_oil_temperature
			// 
			this->nm_oil_temperature->Location = System::Drawing::Point(511, 297);
			this->nm_oil_temperature->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_oil_temperature->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_oil_temperature->Name = L"nm_oil_temperature";
			this->nm_oil_temperature->Size = System::Drawing::Size(83, 26);
			this->nm_oil_temperature->TabIndex = 108;
			this->nm_oil_temperature->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			this->nm_oil_temperature->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_oil_temperature_ValueChanged);
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(8, 212);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(268, 20);
			this->label70->TabIndex = 109;
			this->label70->Text = L"Давление масла от 0 до 10 кг/см2";
			// 
			// nm_fuel_consumption
			// 
			this->nm_fuel_consumption->Location = System::Drawing::Point(511, 268);
			this->nm_fuel_consumption->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_fuel_consumption->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_fuel_consumption->Name = L"nm_fuel_consumption";
			this->nm_fuel_consumption->Size = System::Drawing::Size(83, 26);
			this->nm_fuel_consumption->TabIndex = 108;
			this->nm_fuel_consumption->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_fuel_consumption_ValueChanged);
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(8, 183);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(292, 20);
			this->label69->TabIndex = 109;
			this->label69->Text = L"Напряжение генератора от 0 до 40 В";
			// 
			// nm_fuel_pressure
			// 
			this->nm_fuel_pressure->Location = System::Drawing::Point(511, 239);
			this->nm_fuel_pressure->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_fuel_pressure->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_fuel_pressure->Name = L"nm_fuel_pressure";
			this->nm_fuel_pressure->Size = System::Drawing::Size(83, 26);
			this->nm_fuel_pressure->TabIndex = 108;
			this->nm_fuel_pressure->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_fuel_pressure_ValueChanged);
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(8, 125);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(309, 20);
			this->label67->TabIndex = 109;
			this->label67->Text = L"Напряжение аккумулятора от 0 до 40 В";
			// 
			// nm_oil_pressure
			// 
			this->nm_oil_pressure->Location = System::Drawing::Point(511, 210);
			this->nm_oil_pressure->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_oil_pressure->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_oil_pressure->Name = L"nm_oil_pressure";
			this->nm_oil_pressure->Size = System::Drawing::Size(83, 26);
			this->nm_oil_pressure->TabIndex = 108;
			this->nm_oil_pressure->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_oil_pressure_ValueChanged);
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(8, 96);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(249, 20);
			this->label66->TabIndex = 109;
			this->label66->Text = L"Ток аккумулятора от 0 до 300 А";
			// 
			// nm_generator_voltage
			// 
			this->nm_generator_voltage->Location = System::Drawing::Point(511, 181);
			this->nm_generator_voltage->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_generator_voltage->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_generator_voltage->Name = L"nm_generator_voltage";
			this->nm_generator_voltage->Size = System::Drawing::Size(83, 26);
			this->nm_generator_voltage->TabIndex = 108;
			this->nm_generator_voltage->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 27, 0, 0, 0 });
			this->nm_generator_voltage->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_generator_voltage_ValueChanged);
			// 
			// nm_generator_current
			// 
			this->nm_generator_current->Location = System::Drawing::Point(511, 152);
			this->nm_generator_current->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_generator_current->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_generator_current->Name = L"nm_generator_current";
			this->nm_generator_current->Size = System::Drawing::Size(83, 26);
			this->nm_generator_current->TabIndex = 108;
			this->nm_generator_current->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nm_generator_current->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_generator_current_ValueChanged);
			// 
			// nm_battery_voltage
			// 
			this->nm_battery_voltage->Location = System::Drawing::Point(511, 123);
			this->nm_battery_voltage->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_battery_voltage->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_battery_voltage->Name = L"nm_battery_voltage";
			this->nm_battery_voltage->Size = System::Drawing::Size(83, 26);
			this->nm_battery_voltage->TabIndex = 108;
			this->nm_battery_voltage->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 27, 0, 0, 0 });
			this->nm_battery_voltage->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_battery_voltage_ValueChanged);
			// 
			// nm_battery_current
			// 
			this->nm_battery_current->Location = System::Drawing::Point(511, 94);
			this->nm_battery_current->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_battery_current->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_battery_current->Name = L"nm_battery_current";
			this->nm_battery_current->Size = System::Drawing::Size(83, 26);
			this->nm_battery_current->TabIndex = 108;
			this->nm_battery_current->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nm_battery_current->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_battery_current_ValueChanged);
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(8, 67);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(389, 20);
			this->label62->TabIndex = 109;
			this->label62->Text = L"Номер используемогог блока FLASH от 0 до 4095";
			// 
			// nm_flash_block
			// 
			this->nm_flash_block->Location = System::Drawing::Point(511, 65);
			this->nm_flash_block->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4095, 0, 0, 0 });
			this->nm_flash_block->Name = L"nm_flash_block";
			this->nm_flash_block->Size = System::Drawing::Size(83, 26);
			this->nm_flash_block->TabIndex = 108;
			this->nm_flash_block->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_flash_block_ValueChanged);
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(8, 38);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(385, 20);
			this->label61->TabIndex = 107;
			this->label61->Text = L"Номер используемой страницы FLASH от 0 до 63";
			// 
			// nm_flash_page
			// 
			this->nm_flash_page->Location = System::Drawing::Point(511, 36);
			this->nm_flash_page->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 63, 0, 0, 0 });
			this->nm_flash_page->Name = L"nm_flash_page";
			this->nm_flash_page->Size = System::Drawing::Size(83, 26);
			this->nm_flash_page->TabIndex = 106;
			this->nm_flash_page->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_flash_page_ValueChanged);
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(8, 9);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(351, 20);
			this->label60->TabIndex = 105;
			this->label60->Text = L"Давление(коррекция) от 300 до 805 мм.рт.ст";
			// 
			// nm_pressure
			// 
			this->nm_pressure->Location = System::Drawing::Point(511, 7);
			this->nm_pressure->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_pressure->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_pressure->Name = L"nm_pressure";
			this->nm_pressure->Size = System::Drawing::Size(83, 26);
			this->nm_pressure->TabIndex = 104;
			this->nm_pressure->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 640, 0, 0, 0 });
			this->nm_pressure->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_pressure_ValueChanged);
			// 
			// Controllers
			// 
			this->Controllers->Controls->Add(this->label94);
			this->Controllers->Controls->Add(this->nm_adjust_roll_value);
			this->Controllers->Controls->Add(this->label93);
			this->Controllers->Controls->Add(this->nm_adjust_pitch_value);
			this->Controllers->Controls->Add(this->label92);
			this->Controllers->Controls->Add(this->nm_adjust_course_value);
			this->Controllers->Controls->Add(this->label90);
			this->Controllers->Controls->Add(this->label91);
			this->Controllers->Controls->Add(this->label65);
			this->Controllers->Controls->Add(this->nm_slide_position);
			this->Controllers->Controls->Add(this->nm_elevator_position);
			this->Controllers->Controls->Add(this->nm_elevator_trim_pos);
			this->Controllers->Controls->Add(this->label89);
			this->Controllers->Controls->Add(this->label64);
			this->Controllers->Controls->Add(this->nm_ailerons_position);
			this->Controllers->Controls->Add(this->nm_ailerons_trim_pos);
			this->Controllers->Controls->Add(this->label88);
			this->Controllers->Controls->Add(this->nm_rudder_position);
			this->Controllers->Controls->Add(this->label63);
			this->Controllers->Controls->Add(this->nm_rudder_trim_pos);
			this->Controllers->Location = System::Drawing::Point(4, 32);
			this->Controllers->Name = L"Controllers";
			this->Controllers->Size = System::Drawing::Size(771, 775);
			this->Controllers->TabIndex = 7;
			this->Controllers->Text = L"Управление";
			this->Controllers->UseVisualStyleBackColor = true;
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->Location = System::Drawing::Point(8, 308);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(368, 20);
			this->label94->TabIndex = 117;
			this->label94->Text = L"Юстировочное значение крена от -90 до +90 гр";
			// 
			// nm_adjust_roll_value
			// 
			this->nm_adjust_roll_value->Location = System::Drawing::Point(551, 306);
			this->nm_adjust_roll_value->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_adjust_roll_value->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_adjust_roll_value->Name = L"nm_adjust_roll_value";
			this->nm_adjust_roll_value->Size = System::Drawing::Size(83, 26);
			this->nm_adjust_roll_value->TabIndex = 116;
			this->nm_adjust_roll_value->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_adjust_roll_value_ValueChanged);
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->Location = System::Drawing::Point(8, 278);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(387, 20);
			this->label93->TabIndex = 117;
			this->label93->Text = L"Юстировочное значение тангажа от -90 до +90 гр";
			// 
			// nm_adjust_pitch_value
			// 
			this->nm_adjust_pitch_value->Location = System::Drawing::Point(551, 276);
			this->nm_adjust_pitch_value->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_adjust_pitch_value->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_adjust_pitch_value->Name = L"nm_adjust_pitch_value";
			this->nm_adjust_pitch_value->Size = System::Drawing::Size(83, 26);
			this->nm_adjust_pitch_value->TabIndex = 116;
			this->nm_adjust_pitch_value->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_adjust_pitch_value_ValueChanged);
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->Location = System::Drawing::Point(8, 249);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(351, 20);
			this->label92->TabIndex = 117;
			this->label92->Text = L"Юстировочное значение курса от 0 до 359 гр";
			// 
			// nm_adjust_course_value
			// 
			this->nm_adjust_course_value->Location = System::Drawing::Point(551, 247);
			this->nm_adjust_course_value->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_adjust_course_value->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_adjust_course_value->Name = L"nm_adjust_course_value";
			this->nm_adjust_course_value->Size = System::Drawing::Size(83, 26);
			this->nm_adjust_course_value->TabIndex = 116;
			this->nm_adjust_course_value->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_adjust_course_value_ValueChanged);
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->Location = System::Drawing::Point(8, 76);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(320, 20);
			this->label90->TabIndex = 113;
			this->label90->Text = L"Положение руля высоты от -50 до +50 гр";
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->Location = System::Drawing::Point(8, 197);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(420, 40);
			this->label91->TabIndex = 113;
			this->label91->Text = L"Положение шарика скольжения (боковая перегрузка) \r\nот -0.3 до +0.3 * 1000";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(8, 167);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(400, 20);
			this->label65->TabIndex = 113;
			this->label65->Text = L"Положение триммера руля высоты от -10 до +10 гр";
			// 
			// nm_slide_position
			// 
			this->nm_slide_position->Location = System::Drawing::Point(551, 195);
			this->nm_slide_position->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_slide_position->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_slide_position->Name = L"nm_slide_position";
			this->nm_slide_position->Size = System::Drawing::Size(83, 26);
			this->nm_slide_position->TabIndex = 110;
			this->nm_slide_position->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_slide_position_ValueChanged);
			// 
			// nm_elevator_position
			// 
			this->nm_elevator_position->Location = System::Drawing::Point(551, 74);
			this->nm_elevator_position->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_elevator_position->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_elevator_position->Name = L"nm_elevator_position";
			this->nm_elevator_position->Size = System::Drawing::Size(83, 26);
			this->nm_elevator_position->TabIndex = 110;
			this->nm_elevator_position->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_elevator_position_ValueChanged);
			// 
			// nm_elevator_trim_pos
			// 
			this->nm_elevator_trim_pos->Location = System::Drawing::Point(551, 165);
			this->nm_elevator_trim_pos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_elevator_trim_pos->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_elevator_trim_pos->Name = L"nm_elevator_trim_pos";
			this->nm_elevator_trim_pos->Size = System::Drawing::Size(83, 26);
			this->nm_elevator_trim_pos->TabIndex = 110;
			this->nm_elevator_trim_pos->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_elevator_trim_pos_ValueChanged);
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->Location = System::Drawing::Point(8, 47);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(297, 20);
			this->label89->TabIndex = 114;
			this->label89->Text = L"Положение элеронов от -50 до +50 гр";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(8, 138);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(377, 20);
			this->label64->TabIndex = 114;
			this->label64->Text = L"Положение триммера элеронов от -10 до +10 гр";
			// 
			// nm_ailerons_position
			// 
			this->nm_ailerons_position->Location = System::Drawing::Point(551, 45);
			this->nm_ailerons_position->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_ailerons_position->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_ailerons_position->Name = L"nm_ailerons_position";
			this->nm_ailerons_position->Size = System::Drawing::Size(83, 26);
			this->nm_ailerons_position->TabIndex = 111;
			this->nm_ailerons_position->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_ailerons_position_ValueChanged);
			// 
			// nm_ailerons_trim_pos
			// 
			this->nm_ailerons_trim_pos->Location = System::Drawing::Point(551, 136);
			this->nm_ailerons_trim_pos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_ailerons_trim_pos->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_ailerons_trim_pos->Name = L"nm_ailerons_trim_pos";
			this->nm_ailerons_trim_pos->Size = System::Drawing::Size(83, 26);
			this->nm_ailerons_trim_pos->TabIndex = 111;
			this->nm_ailerons_trim_pos->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_ailerons_trim_pos_ValueChanged);
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->Location = System::Drawing::Point(8, 17);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(363, 20);
			this->label88->TabIndex = 115;
			this->label88->Text = L"Положение руля направления от -50 до +50 гр";
			// 
			// nm_rudder_position
			// 
			this->nm_rudder_position->Location = System::Drawing::Point(551, 15);
			this->nm_rudder_position->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_rudder_position->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_rudder_position->Name = L"nm_rudder_position";
			this->nm_rudder_position->Size = System::Drawing::Size(83, 26);
			this->nm_rudder_position->TabIndex = 112;
			this->nm_rudder_position->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_rudder_position_ValueChanged);
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(8, 108);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(443, 20);
			this->label63->TabIndex = 115;
			this->label63->Text = L"Положение триммера руля направления от -10 до +10 гр";
			// 
			// nm_rudder_trim_pos
			// 
			this->nm_rudder_trim_pos->Location = System::Drawing::Point(551, 106);
			this->nm_rudder_trim_pos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, 0 });
			this->nm_rudder_trim_pos->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999, 0, 0, System::Int32::MinValue });
			this->nm_rudder_trim_pos->Name = L"nm_rudder_trim_pos";
			this->nm_rudder_trim_pos->Size = System::Drawing::Size(83, 26);
			this->nm_rudder_trim_pos->TabIndex = 112;
			this->nm_rudder_trim_pos->ValueChanged += gcnew System::EventHandler(this, &MainForm::nm_rudder_trim_pos_ValueChanged);
			// 
			// timer
			// 
			this->timer->Interval = 10;
			this->timer->Tick += gcnew System::EventHandler(this, &MainForm::timer_Tick);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(778, 924);
			this->Controls->Add(this->toolBar);
			this->Controls->Add(this->MainMenu);
			this->Controls->Add(this->tabControl);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->MainMenu;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MinimumSize = System::Drawing::Size(800, 980);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Имитатор ВПНП";
			this->Click += gcnew System::EventHandler(this, &MainForm::TransmitOff);
			this->MainMenu->ResumeLayout(false);
			this->MainMenu->PerformLayout();
			this->toolBar->ResumeLayout(false);
			this->toolBar->PerformLayout();
			this->tabControl->ResumeLayout(false);
			this->Mode->ResumeLayout(false);
			this->Mode->PerformLayout();
			this->Failures->ResumeLayout(false);
			this->Failures->PerformLayout();
			this->INS->ResumeLayout(false);
			this->INS->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_L_clx))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_B_clx))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_wind_angle_mag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_wind_speed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_drift_angle))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_traj_slope))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_vert))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_vert_pot))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_north))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_east))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_track))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_a_course))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_a_vert))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_otn))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_cmplx))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_n_y))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_gyro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_w_x))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_w_y))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_w_z))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_n_x))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_n_z))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_true))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_track_mag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_course_mag))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_roll))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_pitch))->EndInit();
			this->SVS->ResumeLayout(false);
			this->SVS->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_radio_altitude))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_altitude_trend))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_trend))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_altitude_danger))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_Td2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_Td1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_P_h_stat))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_P_f))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_vert_svs))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_M))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_temp_h))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_temp_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_Q))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_airspeed_prib))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_airspeed_true))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_qfe))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_qnh))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_abs))->EndInit();
			this->SNS->ResumeLayout(false);
			this->SNS->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_L_clx_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_B_clx_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_H_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_track_angle_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_vertical_speed_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_track_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_north_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_v_east_sns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_pdop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_vdop))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_hdop))->EndInit();
			this->RC->ResumeLayout(false);
			this->RC->PerformLayout();
			this->Params->ResumeLayout(false);
			this->Params->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ny_max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_speed_min))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_alpha_max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ny_min))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_alpha_min))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_alpha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_oil_radiator_position))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_flaps_position))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_engine_exhaust_temperature))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_engine_rate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_engine_torque))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_rem_r))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_rem_l))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_oil_temperature))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_consumption))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_fuel_pressure))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_oil_pressure))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_generator_voltage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_generator_current))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_battery_voltage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_battery_current))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_flash_block))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_flash_page))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_pressure))->EndInit();
			this->Controllers->ResumeLayout(false);
			this->Controllers->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_adjust_roll_value))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_adjust_pitch_value))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_adjust_course_value))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_slide_position))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_elevator_position))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_elevator_trim_pos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ailerons_position))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_ailerons_trim_pos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_rudder_position))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nm_rudder_trim_pos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_built_in_test_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_ground_test_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_wait_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_prep_done_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_nav_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		   System::Void par2arinc(t429Word in_arincWord, int32_t& out_number);
		   System::UInt32 parity(uint32_t data);
	private: System::Void cb_vpnp_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_data_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_data_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_cdmk_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_ufos1_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_cdmk_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_ufos1_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_ufos2_valid_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_ufos2_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_mfi10_link_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_mfi12l_link_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_mfi12r_link_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TuningMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void Transmit(System::Object^ sender, System::EventArgs^ e);
	private: System::Void TransmitOff(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_generator_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_engine_fire_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_apu_fire_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_engine_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_pitch_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_roll_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_course_mag_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_course_track_mag_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_course_true_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_course_gyro_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_w_x_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_w_y_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_w_z_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_n_x_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_n_y_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_n_z_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_H_cmplx_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_H_otn_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_a_vert_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_vert_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_vert_pot_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_v_north_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_v_east_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_track_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_a_course_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_traj_slope_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_drift_angle_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_wind_speed_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_wind_angle_mag_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_B_clx_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_L_clx_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_H_abs_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_H_qnh_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_H_qfe_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_airspeed_true_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_airspeed_prib_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_vert_svs_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_M_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_temp_h_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_temp_r_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_P_f_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_P_h_stat_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_Td1_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_Td2_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_altitude_danger_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_radio_altitude_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_altitude_trend_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_trend_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_Q_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_B_clx_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_L_clx_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_H_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_hdop_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_pdop_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_vdop_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_vertical_speed_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_track_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_v_north_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_v_east_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_track_angle_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_QFE_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_QNH_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void rb_QNE_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_baro_update_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_ailerons_trim_n_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_elevator_trim_n_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_rudder_trim_n_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_engine_start_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_manual_mode_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_wow_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_apu_start_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void cb_apu_work_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_pressure_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_flash_page_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_flash_block_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_battery_current_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_battery_voltage_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_generator_current_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_generator_voltage_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_oil_pressure_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_fuel_pressure_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_fuel_consumption_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_oil_temperature_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_fuel_rem_l_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_fuel_rem_r_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_engine_torque_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_engine_rate_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_engine_exhaust_temperature_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_flaps_position_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_oil_radiator_position_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_alpha_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_alpha_min_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_alpha_max_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_ny_min_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_ny_max_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_min_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_speed_max_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_rudder_position_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_ailerons_position_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_elevator_position_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_rudder_trim_pos_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_ailerons_trim_pos_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_elevator_trim_pos_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_slide_position_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_adjust_course_value_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_adjust_pitch_value_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nm_adjust_roll_value_ValueChanged(System::Object^ sender, System::EventArgs^ e);
};
}