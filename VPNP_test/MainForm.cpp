#include "MainForm.h"
#include "SettingsForm.h"
#include "arinc_par_defines.h"

#include <Windows.h>
using namespace VPNPtest; // �������� �������

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	return 0;
}

System::Void VPNPtest::MainForm::ExitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

// ����� ����
System::Void VPNPtest::MainForm::cb_vpnp_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds1.bit.vpnp_valid = ~out->sds1.bit.vpnp_valid;	/* ����������� ���� */
	out->sds1.bit.vpnp_fail = ~out->sds1.bit.vpnp_valid;	/* ����� ���� */
	return System::Void();
}

// ����� ������ �� ��
System::Void VPNPtest::MainForm::cb_data_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds1.bit.data_failure = ~out->sds1.bit.data_failure;	/* ����� ������ �� �� */
	return System::Void();
}

// ��� ������ �� ��
System::Void VPNPtest::MainForm::cb_data_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds1.bit.data_link = ~out->sds1.bit.data_link;	/* ��� ������ �� �� */
	return System::Void();
}

// ����� ����
System::Void VPNPtest::MainForm::cb_cdmk_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2.bit.cdmk_valid = ~out->sds2.bit.cdmk_valid;	/* ����������� ���� */
	out->sds2.bit.cdmk_failure = ~out->sds2.bit.cdmk_valid;	/* ����� ���� */
	return System::Void();
}

// ����� ����� � ���� �� CAN
System::Void VPNPtest::MainForm::cb_cdmk_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2.bit.cdmk_link = ~out->sds2.bit.cdmk_link;		/* ������� ����� � ���� �� CAN */
	return System::Void();
}

// ����� ����� � ����-01 �� CAN #1
System::Void VPNPtest::MainForm::cb_ufos1_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2.bit.ufos1_link = ~out->sds2.bit.ufos1_link;		/* ������� ����� � ����-01 �� CAN #1 */
	return System::Void();
}

// ����� ����-01 #1
System::Void VPNPtest::MainForm::cb_ufos1_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2.bit.ufos1_valid = ~out->sds2.bit.ufos1_valid;		/* ����������� ����-01 #1 */
	out->sds2.bit.ufos1_failure = ~out->sds2.bit.ufos1_valid;	/* ����� ����-01 #1 */
	out->sds2.bit.ufos1_work = out->sds2.bit.ufos1_valid;		/* ������� ������ "������ ����-01 #1" ������� �� ����������� */
	return System::Void();
}

// ����� ����-01 #2
System::Void VPNPtest::MainForm::cb_ufos2_valid_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2.bit.ufos2_valid = ~out->sds2.bit.ufos2_valid;		/* ����������� ����-01 #1 */
	out->sds2.bit.ufos2_failure = ~out->sds2.bit.ufos2_valid;	/* ����� ����-01 #1 */
	out->sds2.bit.ufos2_work = out->sds2.bit.ufos2_valid;		/* ������� ������ "������ ����-01 #1" ������� �� ����������� */
	return System::Void();
}
// ����� ����� � ����-01 �� CAN #2
System::Void VPNPtest::MainForm::cb_ufos2_link_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2.bit.ufos2_link = ~out->sds2.bit.ufos2_link;		/* ������� ����� � ����-01 �� CAN #2 */
	return System::Void();
}

// ��� ������ �� ���-10
System::Void VPNPtest::MainForm::cb_mfi10_link_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds1.bit.mfi10_link_fail = ~out->sds1.bit.mfi10_link_fail;		/* ��� ������ �� ���-10 */
	return System::Void();
}

System::Void VPNPtest::MainForm::cb_mfi12l_link_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds1.bit.mfi12l_link_fail = ~out->sds1.bit.mfi12l_link_fail;		/* ��� ������ �� ���-12 ��� */
	return System::Void();
}

System::Void VPNPtest::MainForm::cb_mfi12r_link_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds1.bit.mfi12r_link_fail = ~out->sds1.bit.mfi12r_link_fail;		/* ��� ������ �� ���-12 ���� */
	return System::Void();
}

// �������� ������� ������ �� ��������� ���� � ��� �� ������������ �������
System::Void VPNPtest::MainForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	out->cnt_p1++; /* ������� ������� ����������� �� 1 */
	out->cnt_p2++; /* ������� ������� ����������� �� 1 */
	out->cnt_p3++; /* ������� ������� ����������� �� 1 */
	out->cnt_ispr++; /* ������� ����������� ����������� �� 1 */
	out->sender_addr = VPNPselected;  /* �������� ������ 0x0002 - ����1, 0x003 - ����2		*/
	Marshal::Copy(inptr, byteArray, 0, sizeof(UDP_OUT));
	udpClient->Send(byteArray, sizeof(UDP_OUT));

	return System::Void();
}

// ���������
System::Void VPNPtest::MainForm::TuningMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	VPNPtest::SettingsForm^ SForm = gcnew SettingsForm();
	SForm->mf = this;
	SForm->SetIP(IP_value, IP_port);
	SForm->ShowDialog();
	SForm->StartPosition = FormStartPosition::CenterParent;
	return System::Void();
}

// ��������� �������� UDP �������
System::Void VPNPtest::MainForm::Transmit(System::Object^ sender, System::EventArgs^ e)
{

	if (System::Net::IPAddress::TryParse(IP_value, ip_addr) != true)
	{
		MessageBox::Show("������ � IP ������ ���!\n �������� �� ����� ��������", "������");
		return System::Void();
	}
	else
	{
		Int32 p = Int32::Parse(IP_port);
		udpClient = gcnew UdpClient();
		udpClient->EnableBroadcast = true;
		ipEndPoint = gcnew System::Net::IPEndPoint(ip_addr->Address, p);
		udpClient->Connect(ipEndPoint);
	}
	timer->Enabled = true;
	this->TransmitOnToolStripMenuItem->Enabled = false;
	this->TransmitOffMenuItem->Enabled = true;
	this->btnTransmitOn->Enabled = false;
	this->btnTransmitOff->Enabled = true;
	return System::Void();
}

// ���������� �������� UDP �������
System::Void VPNPtest::MainForm::TransmitOff(System::Object^ sender, System::EventArgs^ e)
{
	this->TransmitOnToolStripMenuItem->Enabled = true;
	this->TransmitOffMenuItem->Enabled = false;
	this->btnTransmitOn->Enabled = true;
	this->btnTransmitOff->Enabled = false;
	timer->Enabled = false;
	udpClient->Close();
	return System::Void();
}

// ����� ����������
System::Void VPNPtest::MainForm::cb_generator_fail_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.generator_fail = ~out->sds3X.bit.generator_fail; /* ����� ���������� */
	return System::Void();
}

// ����� ���������
System::Void VPNPtest::MainForm::cb_engine_fire_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.engine_fire = ~out->sds3X.bit.engine_fire; /* ����� ��������� */
	return System::Void();
}

// ����� ���
System::Void VPNPtest::MainForm::cb_apu_fire_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.apu_fire = ~out->sds3X.bit.apu_fire; /* ����� ��� */
	return System::Void();
}

// ����� ���������
System::Void VPNPtest::MainForm::cb_engine_failure_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.engine_failure = ~out->sds3X.bit.engine_failure; /* ����� ��������� */
	return System::Void();
}

// ���� �������
System::Void VPNPtest::MainForm::nm_pitch_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���� �������*/
	a429->t_pitch.Fields.ucLabel = AR_OUT_PITCH_ADR;
	a429->t_pitch.Fields.ucSdi = AR_OUT_PITCH_LOW_BIT;
	a429->t_pitch.Fields.ulData = INT32(this->nm_pitch->Value * 1458);
	par2arinc(a429->t_pitch, out->pitch);
	return System::Void();
}

// ���� �����
System::Void VPNPtest::MainForm::nm_roll_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���� ����� */
	a429->t_roll.Fields.ucLabel = AR_OUT_ROLL_ADR;
	a429->t_roll.Fields.ucSdi = AR_OUT_ROLL_LOW_BIT;
	a429->t_roll.Fields.ulData = INT32(this->nm_roll->Value * 1458);
	par2arinc(a429->t_roll, out->roll);
	return System::Void();
}

// ���� ���������
System::Void VPNPtest::MainForm::nm_course_mag_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���� ��������� */
	a429->t_course_mag.Fields.ucLabel = AR_OUT_COURSE_MAG_ADR;
	a429->t_course_mag.Fields.ucSdi = AR_OUT_COURSE_MAG_LOW_BIT;
	a429->t_course_mag.Fields.ulData = INT32(this->nm_course_mag->Value * 1458);
	par2arinc(a429->t_course_mag, out->course_mag);
	return System::Void();
}

// ��������� ������� ����
System::Void VPNPtest::MainForm::nm_course_track_mag_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ��������� ������� ���� */
	a429->t_course_track_mag.Fields.ucLabel = AR_OUT_COURSE_TRACK_MAG_ADR;
	a429->t_course_track_mag.Fields.ucSdi = AR_OUT_COURSE_TRACK_MAG_LOW_BIT;
	a429->t_course_track_mag.Fields.ulData = INT32(this->nm_course_track_mag->Value * 1458);
	par2arinc(a429->t_course_track_mag, out->course_track_mag);
	return System::Void();
}

// �������� ����
System::Void VPNPtest::MainForm::nm_course_true_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* �������� ���� */
	a429->t_course_true.Fields.ucLabel = AR_OUT_COURSE_TRUE_ADR;
	a429->t_course_true.Fields.ucSdi = AR_OUT_COURSE_TRUE_LOW_BIT;
	a429->t_course_true.Fields.ulData = INT32(this->nm_course_true->Value * 1458);
	par2arinc(a429->t_course_true, out->course_true);
	return System::Void();
}

// ��������������� ����
System::Void VPNPtest::MainForm::nm_course_gyro_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ��������������� ����  */
	a429->t_course_gyro.Fields.ucLabel = AR_OUT_COURSE_GYRO_ADR;
	a429->t_course_gyro.Fields.ucSdi = AR_OUT_COURSE_GYRO_LOW_BIT;
	a429->t_course_gyro.Fields.ulData = INT32(this->nm_course_gyro->Value * 1458);  
	par2arinc(a429->t_course_gyro, out->course_gyro);
	return System::Void();
}

// ������� �������� �������
System::Void VPNPtest::MainForm::nm_w_x_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� �������� ������� */
	a429->t_w_x.Fields.ucLabel = AR_OUT_W_X_ADR;
	a429->t_w_x.Fields.ucSdi = AR_OUT_W_X_LOW_BIT;
	a429->t_w_x.Fields.ulData = INT32(this->nm_w_x->Value * 1458);
	par2arinc(a429->t_w_x, out->w_x);
	return System::Void();
}

// ������� �������� �����
System::Void VPNPtest::MainForm::nm_w_y_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� �������� ����� */
	a429->t_w_y.Fields.ucLabel = AR_OUT_W_Y_ADR;
	a429->t_w_y.Fields.ucSdi = AR_OUT_W_Y_LOW_BIT;
	a429->t_w_y.Fields.ulData = INT32(this->nm_w_y->Value * 1458);
	par2arinc(a429->t_w_y, out->w_y);
	return System::Void();
}

// ������� �������� ��������
System::Void VPNPtest::MainForm::nm_w_z_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� �������� �������� */
	a429->t_w_z.Fields.ucLabel = AR_OUT_W_Z_ADR;
	a429->t_w_z.Fields.ucSdi = AR_OUT_W_Z_LOW_BIT;
	a429->t_w_z.Fields.ulData = INT32(this->nm_w_z->Value * 1458);
	par2arinc(a429->t_w_z, out->w_z);
	return System::Void();
}

// ���������� ���������
System::Void VPNPtest::MainForm::nm_n_x_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���������� ��������� */
	a429->t_n_x.Fields.ucLabel = AR_OUT_N_X_ADR;
	a429->t_n_x.Fields.ucSdi = AR_OUT_N_X_LOW_BIT;
	a429->t_n_x.Fields.ulData = INT32(this->nm_n_x->Value * 16000);
	par2arinc(a429->t_n_x, out->n_x);
	return System::Void();
}

// ���������� ���������
System::Void VPNPtest::MainForm::nm_n_y_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���������� ��������� */
	a429->t_n_y.Fields.ucLabel = AR_OUT_N_Y_ADR;
	a429->t_n_y.Fields.ucSdi = AR_OUT_N_Y_LOW_BIT;
	a429->t_n_y.Fields.ulData = INT32(this->nm_n_y->Value * 16000);
	par2arinc(a429->t_n_y, out->n_y);
	return System::Void();
}

// ������� ���������
System::Void VPNPtest::MainForm::nm_n_z_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� ��������� */
	a429->t_n_z.Fields.ucLabel = AR_OUT_N_Z_ADR;
	a429->t_n_z.Fields.ucSdi = AR_OUT_N_Z_LOW_BIT;
	a429->t_n_z.Fields.ulData = INT32(this->nm_n_z->Value * 16000);
	par2arinc(a429->t_n_z, out->n_z);
	return System::Void();
}

// ����������� ������ ������
System::Void VPNPtest::MainForm::nm_H_cmplx_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ����������� ������ ������ */
	a429->t_H_cmplx.Fields.ucLabel = AR_OUT_H_CMPLX_ADR;
	a429->t_H_cmplx.Fields.ucSdi = AR_OUT_H_CMPLX_LOW_BIT;
	a429->t_H_cmplx.Fields.ulData = INT32(this->nm_H_cmplx->Value * 16000);
	par2arinc(a429->t_H_cmplx, out->H_cmplx);
	return System::Void();
}

// ������������� ��������������� ������
System::Void VPNPtest::MainForm::nm_H_otn_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������� ��������������� ������ */
	a429->t_H_otn.Fields.ucLabel = AR_OUT_H_OTN_ADR;
	a429->t_H_otn.Fields.ucSdi = AR_OUT_H_OTN_LOW_BIT;
	a429->t_H_otn.Fields.ulData = INT32(this->nm_H_otn->Value * 16000);
	par2arinc(a429->t_H_otn, out->H_otn);
	return System::Void();
}

// ������������ ���������
System::Void VPNPtest::MainForm::nm_a_vert_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������ ��������� */
	a429->t_a_vert.Fields.ucLabel = AR_OUT_A_VERT_ADR;
	a429->t_a_vert.Fields.ucSdi = AR_OUT_A_VERT_LOW_BIT;
	a429->t_a_vert.Fields.ulData = INT32(this->nm_a_vert->Value * 16000);
	par2arinc(a429->t_a_vert, out->a_vert);
	return System::Void();
}

// ������������ ��������
System::Void VPNPtest::MainForm::nm_speed_vert_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������ �������� */
	a429->t_speed_vert.Fields.ucLabel = AR_OUT_SPEED_VERT_ADR;
	a429->t_speed_vert.Fields.ucSdi = AR_OUT_SPEED_VERT_LOW_BIT;
	a429->t_speed_vert.Fields.ulData = INT32(this->nm_speed_vert->Value * 16000);
	par2arinc(a429->t_speed_vert, out->speed_vert);
	return System::Void();
}

// ������������� ������������ ��������
System::Void VPNPtest::MainForm::nm_speed_vert_pot_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������� ������������ �������� */
	a429->t_speed_vert_pot.Fields.ucLabel = AR_OUT_SPEED_VERT_POT_ADR;
	a429->t_speed_vert_pot.Fields.ucSdi = AR_OUT_SPEED_VERT_POT_LOW_BIT;
	a429->t_speed_vert_pot.Fields.ulData = INT32(this->nm_speed_vert_pot->Value * 16000);
	par2arinc(a429->t_speed_vert_pot, out->speed_vert_pot);
	return System::Void();
}

// ������� �������� N/S
System::Void VPNPtest::MainForm::nm_v_north_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� �������� N/S */
	a429->t_v_north.Fields.ucLabel = AR_OUT_V_NORTH_ADR;
	a429->t_v_north.Fields.ucSdi = AR_OUT_V_NORTH_LOW_BIT;
	a429->t_v_north.Fields.ulData = INT32(this->nm_v_north->Value * 16000);
	par2arinc(a429->t_v_north, out->v_north);
	return System::Void();
}

// ������� �������� E/W
System::Void VPNPtest::MainForm::nm_v_east_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� �������� E/W */
	a429->t_v_east.Fields.ucLabel = AR_OUT_V_EAST_ADR;
	a429->t_v_east.Fields.ucSdi = AR_OUT_V_EAST_LOW_BIT;
	a429->t_v_east.Fields.ulData = INT32(this->nm_v_east->Value * 16000);
	par2arinc(a429->t_v_east, out->v_east);
	return System::Void();
}

// ������� ��������
System::Void VPNPtest::MainForm::nm_speed_track_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������� �������� */
	a429->t_speed_track.Fields.ucLabel = AR_OUT_SPEED_TRACK_ADR;
	a429->t_speed_track.Fields.ucSdi = AR_OUT_SPEED_TRACK_LOW_BIT;
	a429->t_speed_track.Fields.ulData = INT32(this->nm_speed_track->Value * 16000);
	par2arinc(a429->t_speed_track, out->speed_track);
	return System::Void();
}

// ��������� ����� ���������� ������
System::Void VPNPtest::MainForm::nm_a_course_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ��������� ����� ���������� ������ */
	a429->t_a_course.Fields.ucLabel = AR_OUT_A_COURSE_ADR;
	a429->t_a_course.Fields.ucSdi = AR_OUT_A_COURSE_LOW_BIT;
	a429->t_a_course.Fields.ulData = INT32(this->nm_a_course->Value * 16000);
	par2arinc(a429->t_a_course, out->a_course);
	return System::Void();
}

// ���� ������� ����������
System::Void VPNPtest::MainForm::nm_traj_slope_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���� ������� ���������� */
	a429->t_traj_slope.Fields.ucLabel = AR_OUT_TRAJ_SLOPE_ADR;
	a429->t_traj_slope.Fields.ucSdi = AR_OUT_TRAJ_SLOPE_LOW_BIT;
	a429->t_traj_slope.Fields.ulData = INT32(this->nm_traj_slope->Value * 16000);
	par2arinc(a429->t_traj_slope, out->traj_slope);
	return System::Void();
}

// ���� �����
System::Void VPNPtest::MainForm::nm_drift_angle_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���� ����� */
	a429->t_drift_angle.Fields.ucLabel = AR_OUT_DRIFT_ANGLE_ADR;
	a429->t_drift_angle.Fields.ucSdi = AR_OUT_DRIFT_ANGLE_LOW_BIT;
	a429->t_drift_angle.Fields.ulData = INT32(this->nm_drift_angle->Value * 16000);
	par2arinc(a429->t_drift_angle, out->drift_angle);
	return System::Void();
}

// �������� �����
System::Void VPNPtest::MainForm::nm_wind_speed_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* �������� ����� */
	a429->t_wind_speed.Fields.ucLabel = AR_OUT_WIND_SPEED_ADR;
	a429->t_wind_speed.Fields.ucSdi = AR_OUT_WIND_SPEED_LOW_BIT;
	a429->t_wind_speed.Fields.ulData = INT32(this->nm_wind_speed->Value * 16000);
	par2arinc(a429->t_wind_speed, out->wind_speed);
	return System::Void();
}

// ��������� ����������� �����
System::Void VPNPtest::MainForm::nm_wind_angle_mag_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->wind_angle_mag = INT32(this->nm_wind_angle_mag->Value);  /* ��������� ����������� ����� */
	return System::Void();
}

// �������������� ���������� ������
System::Void VPNPtest::MainForm::nm_B_clx_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	Decimal B;
	B = this->nm_B_clx->Value;
	out->B_clx_head = INT32(this->nm_B_clx->Value.Truncate(B));  /* �������������� ���������� ������ ������� ����� */
	out->B_clx_tail = INT32((DOUBLE(this->nm_B_clx->Value) - out->B_clx_head) * 1000000);  /* �������������� ���������� ������ ������� ����� */
	return System::Void();
}

// �������������� ���������� �������
System::Void VPNPtest::MainForm::nm_L_clx_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	Decimal L;
	L = this->nm_L_clx->Value;
	out->L_clx_head = INT32(this->nm_L_clx->Value.Truncate(L));  /* �������������� ���������� ������� ������� ����� */
	out->L_clx_tail = INT32((DOUBLE(this->nm_L_clx->Value) - out->L_clx_head) * 1000000);  /* �������������� ���������� ������� ������� ����� */
	return System::Void();
}

// ���������� ��������������� ������
System::Void VPNPtest::MainForm::nm_H_abs_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ���������� ��������������� ������ */
	a429->t_H_abs.Fields.ucLabel = AR_OUT_H_ABS_ADR;
	a429->t_H_abs.Fields.ucSdi = AR_OUT_H_ABS_LOW_BIT;
	a429->t_H_abs.Fields.ulData = INT32(this->nm_H_abs->Value * 16000);
	par2arinc(a429->t_H_abs, out->H_abs);
	return System::Void();
}

// ������������� ����������(��������� �� QNH)
System::Void VPNPtest::MainForm::nm_H_qnh_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������� ����������(��������� �� QNH) */
	a429->t_H_qnh.Fields.ucLabel = AR_OUT_H_QNH_ADR;
	a429->t_H_qnh.Fields.ucSdi = AR_OUT_H_QNH_LOW_BIT;
	a429->t_H_qnh.Fields.ulData = INT32(this->nm_H_qnh->Value * 16000);
	par2arinc(a429->t_H_qnh, out->H_qnh);
	return System::Void();
}

// ������������� ���������� (��������� �� QFE)
System::Void VPNPtest::MainForm::nm_H_qfe_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������� ����������(��������� �� QF) */
	a429->t_H_qfe.Fields.ucLabel = AR_OUT_H_QFE_ADR;
	a429->t_H_qfe.Fields.ucSdi = AR_OUT_H_QFE_LOW_BIT;
	a429->t_H_qfe.Fields.ulData = INT32(this->nm_H_qfe->Value * 16000);
	par2arinc(a429->t_H_qfe, out->H_qfe);
	return System::Void();
}

// �������� (���������) ��������
System::Void VPNPtest::MainForm::nm_airspeed_true_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* �������� (���������) �������� */
	a429->t_airspeed_true.Fields.ucLabel = AR_OUT_AIR_SPEED_TRUE_SVS_ADR;
	a429->t_airspeed_true.Fields.ucSdi = AR_OUT_AIR_SPEED_TRUE_SVS_LOW_BIT;
	a429->t_airspeed_true.Fields.ulData = INT32(this->nm_airspeed_true->Value * 16000);
	par2arinc(a429->t_airspeed_true, out->airspeed_true);
	return System::Void();
}

// ��������� ��������
System::Void VPNPtest::MainForm::nm_airspeed_prib_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ��������� �������� */
	a429->t_airspeed_prib.Fields.ucLabel = AR_OUT_AIR_SPEED_PRIB_SVS_ADR;
	a429->t_airspeed_prib.Fields.ucSdi = AR_OUT_AIR_SPEED_PRIB_SVS_LOW_BIT;
	a429->t_airspeed_prib.Fields.ulData = INT32(this->nm_airspeed_prib->Value * 16000);
	par2arinc(a429->t_airspeed_prib, out->airspeed_prib);
	return System::Void();
}

// ������������ ��������
System::Void VPNPtest::MainForm::nm_speed_vert_svs_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	/* ������������ �������� */
	a429->t_speed_vert_svs.Fields.ucLabel = AR_OUT_SPEED_VERT_SVS_ADR;
	a429->t_speed_vert_svs.Fields.ucSdi = AR_OUT_SPEED_VERT_SVS_LOW_BIT;
	a429->t_speed_vert_svs.Fields.ulData = INT32(this->nm_speed_vert_svs->Value * 16000);
	par2arinc(a429->t_speed_vert_svs, out->speed_vert_svs);
	return System::Void();
}

// ����� ���� ������ 
System::Void VPNPtest::MainForm::nm_M_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->M = INT32(this->nm_M->Value);  /* ����� ���� ������  */
	return System::Void();
}

// ����������� ��������� �������
System::Void VPNPtest::MainForm::nm_temp_h_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->temp_h = INT32(this->nm_temp_h->Value);  /* ����������� ��������� �������  */
	return System::Void();
}

// ����������� ����������
System::Void VPNPtest::MainForm::nm_temp_r_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->temp_r = INT32(this->nm_temp_r->Value);  /* ����������� ����������  */
	return System::Void();
}

// ������ ��������
System::Void VPNPtest::MainForm::nm_P_f_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->P_f = INT32(this->nm_P_f->Value);  /* ������ ��������  */
	return System::Void();
}

// ����������� �������� �������
System::Void VPNPtest::MainForm::nm_P_h_stat_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->P_h_stat = INT32(this->nm_P_h_stat->Value);  /* ����������� �������� �������  */
	return System::Void();
}

// ����������� ������� �������� ������� �1 
System::Void VPNPtest::MainForm::nm_Td1_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->Td1 = INT32(this->nm_Td1->Value);   /* ����������� ������� �������� ������� �1    [��] */
	return System::Void();
}

// ����������� ������� �������� ������� �2  
System::Void VPNPtest::MainForm::nm_Td2_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->Td2 = INT32(this->nm_Td2->Value);   /* ����������� ������� �������� ������� �2    [��] */
	return System::Void();
}
// ������� ������
System::Void VPNPtest::MainForm::nm_altitude_danger_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->altitude_danger = INT32(this->nm_altitude_danger->Value);   /* ������� ������ */
	return System::Void();
}

// ������ �� ���������������
System::Void VPNPtest::MainForm::nm_radio_altitude_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->radio_altitude = INT32(this->nm_radio_altitude->Value);   /* ������ �� ��������������� */
	return System::Void();
}

// ����� ������ Habs
System::Void VPNPtest::MainForm::nm_altitude_trend_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->altitude_trend = INT32(this->nm_altitude_trend->Value);   /* ����� ������ Habs */
	return System::Void();
}

// ����� �������� ��������� 
System::Void VPNPtest::MainForm::nm_speed_trend_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->speed_trend = INT32(this->nm_speed_trend->Value);   /* ����� �������� ���������  */
	return System::Void();
}

// ���������� �����
System::Void VPNPtest::MainForm::nm_Q_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->Q = INT32(this->nm_Q->Value);   /* ���������� �����  */
	return System::Void();
}

// ���. �������������� ���������� ������
System::Void VPNPtest::MainForm::nm_B_clx_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	Decimal B;
	B = this->nm_B_clx_sns->Value;
	out->B_clx_head_sns = INT32(this->nm_B_clx_sns->Value.Truncate(B));  /* �������������� ���������� ������ ������� ����� */
	out->B_clx_tail_sns = INT32((DOUBLE(this->nm_B_clx_sns->Value) - out->B_clx_head_sns) * 1000000);  /* �������������� ���������� ������ ������� ����� */
	return System::Void();
}

// ���. �������������� ���������� �������
System::Void VPNPtest::MainForm::nm_L_clx_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	Decimal L;
	L = this->nm_L_clx_sns->Value;
	out->L_clx_head_sns = INT32(this->nm_L_clx_sns->Value.Truncate(L));  /* �������������� ���������� ������� ������� ����� */
	out->L_clx_tail_sns = INT32((DOUBLE(this->nm_L_clx_sns->Value) - out->L_clx_head_sns) * 1000000);  /* �������������� ���������� ������� ������� ����� */
	return System::Void();
}

// ������ ���
System::Void VPNPtest::MainForm::nm_H_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->H_sns = INT32(this->nm_H_sns->Value);   /* ������ ��� [�] */
	return System::Void();
}

// �������������� ������ HDOP 
System::Void VPNPtest::MainForm::nm_hdop_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->hdop = INT32(this->nm_hdop->Value);   /*�������������� ������ HDOP  ���������� �� 10*/
	return System::Void();
}

// �������������� ������ PDOP 
System::Void VPNPtest::MainForm::nm_pdop_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->pdop = INT32(this->nm_pdop->Value);   /*�������������� ������ PDOP  ���������� �� 10*/
	return System::Void();
}

// �������������� ������ VDOP 
System::Void VPNPtest::MainForm::nm_vdop_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->vdop = INT32(this->nm_vdop->Value);   /*�������������� ������ VDOP  ���������� �� 10*/
	return System::Void();
}

// ���. ������������ ��������
System::Void VPNPtest::MainForm::nm_vertical_speed_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->vertical_speed_sns = INT32(this->nm_vertical_speed_sns->Value);   /* ������������ �������� [�/�] */
	return System::Void();
}


// ���� ���������� ��������� 
System::Void VPNPtest::MainForm::rb_built_in_test_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_built_in_test->Checked)	 /* ���� ���������� ��������� */
		out->sds1.bit.built_in_test = 0x01;
	else
		out->sds1.bit.built_in_test = 0x00;

	return System::Void();
}

// ������� ��������
System::Void VPNPtest::MainForm::nm_speed_track_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->speed_track_sns = INT32(this->nm_speed_track_sns->Value);   /*������� �������� */
	return System::Void();
}

// ������� �������� N/S
System::Void VPNPtest::MainForm::nm_v_north_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->v_north_sns = INT32(this->nm_v_north_sns->Value);   /*������� �������� N/S  */
	return System::Void();
}

// ������� �������� E/W
System::Void VPNPtest::MainForm::nm_v_east_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->v_east_sns = INT32(this->nm_v_east_sns->Value);   /*������� �������� E/W  */
	return System::Void();
}

// ������� ����
System::Void VPNPtest::MainForm::nm_track_angle_sns_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->track_angle_sns = INT32(this->nm_track_angle_sns->Value);    /* ������� ���� */
	return System::Void();
}

// ������� ��������� ����������. QFE
System::Void VPNPtest::MainForm::rb_QFE_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_QFE->Checked)		/* ������� ��������� ����������. QFE */
	{
		out->sds2X.bit.baro0 = 0x00;
		out->sds2X.bit.baro1 = 0x00;
	}
	return System::Void();
}

// ������� ��������� ����������. QNH
System::Void VPNPtest::MainForm::rb_QNH_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_QNH->Checked)		/* ������� ��������� ����������. QNH */
	{
		out->sds2X.bit.baro0 = 0x01;
		out->sds2X.bit.baro1 = 0x00;
	}
	return System::Void();
}

// ������� ��������� ����������. QNE
System::Void VPNPtest::MainForm::rb_QNE_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_QNE->Checked)		/* ������� ��������� ����������. QNE */
	{
		out->sds2X.bit.baro0 = 0x00;
		out->sds2X.bit.baro1 = 0x01;
	}
	return System::Void();
}

// ������� "������ ��������� ���������� ���������"
System::Void VPNPtest::MainForm::cb_baro_update_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds2X.bit.baro_update = ~out->sds2X.bit.baro_update;		/* ������� "������ ��������� ���������� ���������" */
	return System::Void();
}

// ����������� ��������� �������� ��������
System::Void VPNPtest::MainForm::cb_ailerons_trim_n_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.ailerons_trim_n = ~out->sds3X.bit.ailerons_trim_n;		/* ����������� ��������� �������� �������� */
	return System::Void();
}

// ����������� ��������� �������� ��
System::Void VPNPtest::MainForm::cb_elevator_trim_n_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.elevator_trim_n = ~out->sds3X.bit.elevator_trim_n;		/* ����������� ��������� �������� �� */
	return System::Void();
}

// ����������� ��������� �������� ��
System::Void VPNPtest::MainForm::cb_rudder_trim_n_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.rudder_trim_n = ~out->sds3X.bit.rudder_trim_n;	/* ����������� ��������� �������� �� */
	return System::Void();
}

// ������ ���������
System::Void VPNPtest::MainForm::cb_engine_start_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.engine_start = ~out->sds3X.bit.engine_start;	/* ������ ��������� */
	return System::Void();
}

// ������ ����� 
System::Void VPNPtest::MainForm::cb_manual_mode_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.manual_mode = ~out->sds3X.bit.manual_mode;	/* ������ ����� */
	return System::Void();
}

// ����� ������
System::Void VPNPtest::MainForm::cb_wow_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.wow = ~out->sds3X.bit.wow;	/* ����� ������ */
	return System::Void();
}

// ��� ������
System::Void VPNPtest::MainForm::cb_apu_start_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.apu_start = ~out->sds3X.bit.apu_start;	/* ��� ������ */
	return System::Void();
}

// ��� ������
System::Void VPNPtest::MainForm::cb_apu_work_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->sds3X.bit.apu_work = ~out->sds3X.bit.apu_work;	/* ��� ������ */
	return System::Void();
}

// ��������(���������)
System::Void VPNPtest::MainForm::nm_pressure_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->pressure = INT32(this->nm_pressure->Value);    /* ��������(���������) */
	return System::Void();
}

// ����� ������������ �������� FLASH
System::Void VPNPtest::MainForm::nm_flash_page_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->flash_page = INT32(this->nm_flash_page->Value);    /* ����� ������������ �������� FLASH */
	return System::Void();
}

// ����� �������������� ����� FLASH
System::Void VPNPtest::MainForm::nm_flash_block_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->flash_page = INT32(this->nm_flash_page->Value);    /* ����� �������������� ����� FLASH */
	return System::Void();
}

// ��� ������������
System::Void VPNPtest::MainForm::nm_battery_current_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->battery_current = INT32(this->nm_battery_current->Value);    /* ��� ������������ */
	return System::Void();
}

// ���������� ������������
System::Void VPNPtest::MainForm::nm_battery_voltage_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->battery_voltage = INT32(this->nm_battery_voltage->Value);    /* ���������� ������������ */
	return System::Void();
}

// ��� ����������
System::Void VPNPtest::MainForm::nm_generator_current_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->generator_current = INT32(this->nm_generator_current->Value);    /* ��� ���������� */
	return System::Void();
}

// ���������� ����������
System::Void VPNPtest::MainForm::nm_generator_voltage_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->generator_voltage = INT32(this->nm_generator_voltage->Value);    /* ���������� ���������� */
	return System::Void();
}

// �������� �����
System::Void VPNPtest::MainForm::nm_oil_pressure_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->oil_pressure = INT32(this->nm_oil_pressure->Value);    /* �������� ����� */
	return System::Void();
}

// �������� �������
System::Void VPNPtest::MainForm::nm_fuel_pressure_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->fuel_pressure = INT32(this->nm_fuel_pressure->Value);    /* �������� ������� */
	return System::Void();
}

// ������ �������
System::Void VPNPtest::MainForm::nm_fuel_consumption_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->fuel_consumption = INT32(this->nm_fuel_consumption->Value);    /* ������ ������� */
	return System::Void();
}

// ����������� �����
System::Void VPNPtest::MainForm::nm_oil_temperature_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->oil_temperature = INT32(this->nm_oil_temperature->Value);    /* ����������� ����� */
	return System::Void();
}

// ������� ������� � ����� ����
System::Void VPNPtest::MainForm::nm_fuel_rem_l_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->fuel_rem_l = INT32(this->nm_fuel_rem_l->Value);    /* ������� ������� � ����� ���� */
	out->fuel_rem = out->fuel_rem_l + out->fuel_rem_r;		/* ����� ������� ������� */
	return System::Void();
}

// ������� ������� � ������ ����
System::Void VPNPtest::MainForm::nm_fuel_rem_r_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->fuel_rem_r = INT32(this->nm_fuel_rem_r->Value);    /* ������� ������� � ������ ���� */
	out->fuel_rem = out->fuel_rem_l + out->fuel_rem_r;		/* ����� ������� ������� */
	return System::Void();
}

// �������� ��������� �������/���� �����
System::Void VPNPtest::MainForm::nm_engine_torque_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->engine_torque = INT32(this->nm_engine_torque->Value);    /* �������� ��������� �������/���� ����� */
	return System::Void();
}

// �������� �������� ���������
System::Void VPNPtest::MainForm::nm_engine_rate_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->engine_rate = INT32(this->nm_engine_rate->Value);    /* �������� �������� ��������� */
	return System::Void();
}

// ����������� ��������� ����� ���������
System::Void VPNPtest::MainForm::nm_engine_exhaust_temperature_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->engine_exhaust_temperature = INT32(this->nm_engine_exhaust_temperature->Value);    /* ����������� ��������� ����� ��������� */
	return System::Void();
}

// ��������� ���������
System::Void VPNPtest::MainForm::nm_flaps_position_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->flaps_position = INT32(this->nm_flaps_position->Value);    /* ��������� ��������� */
	return System::Void();
}

// ��������� ������� ��������������
System::Void VPNPtest::MainForm::nm_oil_radiator_position_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->oil_radiator_position = INT32(this->nm_oil_radiator_position->Value);    /* ��������� ������� �������������� */
	return System::Void();
}

// ��������� ���� �����
System::Void VPNPtest::MainForm::nm_alpha_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->alpha = INT32(this->nm_alpha->Value);    /* ��������� ���� ����� */
	return System::Void();
}

// ���� ����� ���������� ����������
System::Void VPNPtest::MainForm::nm_alpha_min_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->alpha_min = INT32(this->nm_alpha_min->Value);    /* ���� ����� ���������� ���������� */
	return System::Void();
}

// ���� ����� ����������� ����������
System::Void VPNPtest::MainForm::nm_alpha_max_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->alpha_max = INT32(this->nm_alpha_max->Value);    /* ���� ����� ����������� ���������� */
	return System::Void();
}

// ���������� ���������� ����������
System::Void VPNPtest::MainForm::nm_ny_min_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->ny_min = INT32(this->nm_ny_min->Value);    /* ���������� ���������� ���������� */
	return System::Void();
}

// ���������� ����������� ����������
System::Void VPNPtest::MainForm::nm_ny_max_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->ny_max = INT32(this->nm_ny_max->Value);    /* ���������� ����������� ���������� */
	return System::Void();
}

// �������� ���������� ����������
System::Void VPNPtest::MainForm::nm_speed_min_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->speed_min = INT32(this->nm_speed_min->Value);    /* �������� ���������� ���������� */
	return System::Void();
}

// �������� ����������� ����������
System::Void VPNPtest::MainForm::nm_speed_max_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->speed_max = INT32(this->nm_speed_max->Value);    /* �������� ����������� ���������� */
	return System::Void();
}

// ��������� ���� �����������
System::Void VPNPtest::MainForm::nm_rudder_position_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->rudder_position = INT32(this->nm_rudder_position->Value);    /* ��������� ���� ����������� */
	return System::Void();
}

// ��������� ��������
System::Void VPNPtest::MainForm::nm_ailerons_position_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->ailerons_position = INT32(this->nm_ailerons_position->Value);    /* ��������� �������� */
	return System::Void();
}

// ��������� ���� ������
System::Void VPNPtest::MainForm::nm_elevator_position_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->elevator_position = INT32(this->nm_elevator_position->Value);    /* ��������� ���� ������ */
	return System::Void();
}

// ��������� �������� ���� �����������
System::Void VPNPtest::MainForm::nm_rudder_trim_pos_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->rudder_trim_pos = INT32(this->nm_rudder_trim_pos->Value);    /* ��������� �������� ���� ����������� */
	return System::Void();
}

// ��������� �������� ��������
System::Void VPNPtest::MainForm::nm_ailerons_trim_pos_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->ailerons_trim_pos = INT32(this->nm_ailerons_trim_pos->Value);    /* ��������� �������� �������� */
	return System::Void();
}

// ��������� �������� ���� ������
System::Void VPNPtest::MainForm::nm_elevator_trim_pos_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->elevator_trim_pos = INT32(this->nm_elevator_trim_pos->Value);    /* ��������� �������� ���� ������ */
	return System::Void();
}

// ��������� ������ ����������(������� ����������)
System::Void VPNPtest::MainForm::nm_slide_position_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->slide_position = INT32(this->nm_slide_position->Value);    /* ��������� ������ ����������(������� ����������) */
	return System::Void();
}

// ������������ �������� ����� �� 0 �� 359 ��
System::Void VPNPtest::MainForm::nm_adjust_course_value_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->adjust_course_value = INT32(this->nm_adjust_course_value->Value);    /* ������������ �������� ����� �� 0 �� 359 �� */
	return System::Void();
}

// ������������ �������� ������� �� -90 �� 90 ��
System::Void VPNPtest::MainForm::nm_adjust_pitch_value_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->adjust_pitch_value = INT32(this->nm_adjust_pitch_value->Value);    /* ������������ ��������  ������� �� -90 �� 90 �� */
	return System::Void();
}

// ������������ �������� ����� �� -90 �� 90 ��
System::Void VPNPtest::MainForm::nm_adjust_roll_value_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	out->adjust_roll_value = INT32(this->nm_adjust_roll_value->Value) * 100;    /* ������������ ��������  ����� �� -90 �� 90 �� */
	return System::Void();
}


// �������� ��������
System::Void VPNPtest::MainForm::rb_ground_test_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_ground_test->Checked)		/* �������� �������� */
		out->sds1.bit.ground_test = 0x01;
	else
		out->sds1.bit.ground_test = 0x00;

	return System::Void();
}

// ��������
System::Void VPNPtest::MainForm::rb_wait_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_wait->Checked)		/* �������� */
		out->sds1.bit.wait = 0x01;
	else
		out->sds1.bit.wait = 0x00;

	return System::Void();
}

// ���������� ���������
System::Void VPNPtest::MainForm::rb_prep_done_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_prep_done->Checked)		/* ���������� ��������� */
		out->sds1.bit.prep_done = 0x01;
	else
		out->sds1.bit.prep_done = 0x00;

	return System::Void();
}

// ���������
System::Void VPNPtest::MainForm::rb_nav_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->rb_nav->Checked)		/* ��������� */
		out->sds1.bit.nav = 0x01;
	else
		out->sds1.bit.nav = 0x00;

	return System::Void();
}

Void MainForm::Init(void)
{
	byteArray = gcnew array<Byte>(sizeof(UDP_OUT));
	inptr = Marshal::AllocHGlobal(sizeof(UDP_OUT));
	out = (UDP_OUT*)inptr.ToPointer();
	memset(out, 0, sizeof(UDP_OUT));
	// ����������� ��� ���������� � ������� ARINC429 
	a429byteArray = gcnew array<Byte>(sizeof(ARINC429values));
	a429ptr = Marshal::AllocHGlobal(sizeof(ARINC429values));
	a429 = (ARINC429values*)a429ptr.ToPointer();
	memset(out, 0, sizeof(ARINC429values));
	
	// ��������� ������
	out->preface_1 = 0xCD;		/* ���������	0xCDEFFA01		*/
	out->preface_2 = 0xEF;		/* ���������					*/
	out->preface_3 = 0xFA;		/* ���������					*/
	out->preface_4 = 0x01;		/* ���������					*/
	out->reciever_addr = 0x0001;/* ������� ������	 ���		*/
	out->id = 0x0001;   /* � ������	0x0001              */
	out->reserv_1 = 0x0000;   /* ���������������	0x0000      */
	out->reserv_2 = 0x0000;   /* ���������������	0x0000      */
	out->reserv_3 = 0x0000;   /* ���������������	0x0000      */
	out->size = sizeof(UDP_OUT);/* ����� ����� ������	0x0242  */
	//------------ sds1 -----------
	out->sds1.bit.vpnp_valid = 0x01;	/* ����������� ����		*/
	out->sds1.bit.built_in_test = 0x01; /* ���� ���������� ��������� */
	//------------ sds2 -----------
	out->sds2.bit.cdmk_valid = 0x01;	/* ����������� ����		*/
	out->sds2.bit.cdmk_link = 0x01;		/* ������� ����� � ���� �� CAN */
	out->sds2.bit.ufos1_valid = 0x01;	/* ����������� ����-01 #1 */
	out->sds2.bit.ufos1_link = 0x01;	/* ������� ����� � ����-01 �� CAN #1 */
	out->sds2.bit.ufos1_work = 0x01;	/* ���� - 01 #1 � ������ "������" */
	out->sds2.bit.ufos2_valid = 0x01;	/* ����������� ����-01 #2 */
	out->sds2.bit.ufos2_link = 0x01;	/* ������� ����� � ����-01 �� CAN #2 */
	out->sds2.bit.ufos2_work = 0x01;	/* ���� - 01 #2 � ������ "������" */

}

/// <summary>
///  �������������� ����� � ������ ARINC 429
/// </summary>
/// <param name="arincWordNo"></param>
/// <param name="number"></param>
/// <returns></returns>
System::Void VPNPtest::MainForm::par2arinc(t429Word in_arincWord, int32_t& out_number)
{
	in_arincWord.Fields.ucStatus = 3;                // �������
	in_arincWord.Fields.ucParity = parity(in_arincWord.ul429Data); // ?������
	out_number = in_arincWord.ul429Data;
}
	
	
	
// �������� ��������
System::UInt32 VPNPtest::MainForm::parity(uint32_t value)
{
		unsigned int parity = 0;

		for (int x = 0; x < 31; x++)
		{
			parity += (value & 0x0001); value = value >> 1;
		}
		if (parity & 0x1)
			return 1;
		else return 0;

}