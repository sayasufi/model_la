#include "SettingsForm.h"

void VPNPtest::SettingsForm::SetIP(String^ IP, String^ Port)
{
    MFI_IP = IP;
    this->IP_text->Text = MFI_IP;
    MFI_port = Port;
    this->PortNmb->Text = MFI_port;
    this->cb_VPNPselect->SelectedIndex = mf->VPNPselected-2;
}

System::Void VPNPtest::SettingsForm::bt_OK_Click(System::Object^ sender, System::EventArgs^ e)
{
    MFI_IP = this->IP_text->Text;
    MFI_port = this->PortNmb->Text;
    mf->IP_value = MFI_IP;
    mf->IP_port = MFI_port;
    mf->VPNPselected = this->cb_VPNPselect->SelectedIndex+2;
    Close();
    return System::Void();
}
