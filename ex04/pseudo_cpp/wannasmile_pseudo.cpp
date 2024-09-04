void relaunchSelf(std::string addrIP)
{
  char *filename;
  WCHAR *commandLine;
  DWORD ExitCode;
  struct _PROCESS_INFORMATION ProcessInformation;
  struct _STARTUPINFOW StartupInfo;

  memset(&StartupInfo, 0, sizeof(StartupInfo));
  StartupInfo.cb = 104;
  memset(&ProcessInformation, 0, sizeof(ProcessInformation));
  filename = __p___argv();
  commandLine = std::wstring(filename + " wd3r05OZxpeX " + addrIP)  // 'wannasmile wd3r05OZxpeX m5OYhJuckoSbmZiEm56Y'
  if (CreateProcessW(0, commandLine, 0, 0, 0, 0, 0, 0, &StartupInfo, &ProcessInformation))
  {
    WaitForSingleObject(ProcessInformation.hProcess, 0xFFFFFFFF);
    GetExitCodeProcess(ProcessInformation.hProcess, &ExitCode);
    if (ExitCode == 1)
    {
      std::wstring::(L"Congratulations! 太棒了！");
      death(L"Bravo!", 10000); // death => pestillance => niceguy !
    }
    else
    {
      DeleteFileA(filename);
    }
    displayMsgBox(L"妈妈！妈妈你在哪里！我找不到你……我哭得肚子疼");
    CloseHandle(ProcessInformation.hProcess);
    CloseHandle(ProcessInformation.hThread);
  }
  else
  {
    displayMsgBox(L"Failed to create process for pig. gronk gronk (bruit du cochon).");
  }
  return;
}

int displayMsgBox(std::wstring strToDisplay)
{
  return MessageBoxW(0, strToDisplay, L"@*#&@(83)", 16);
}

void makePing(std::string ip2)
{
    uint32_t dest_addr = inet_addr(ip2);
    int64_t handle = IcmpCreateFile();
    if (handle == -1)
    {
        std::cerr("Unable to open handle.");
        exit(0);
    }
    int32_t buff_size = 72;
    void* buff_response = malloc(buff_size);
    if (buff_response == 0)
    {
        std::cerr("Unable to allocate memory.");
        IcmpCloseHandle(handle);
        exit(0);
    }
    int ret = 0;
    if (IcmpSendEcho(handle, dest_addr, "dataMakeSens", 32, 0, buff_response, buff_size, 1000) != 0)
        ret = 1;
    free(buff_response);
    IcmpCloseHandle(handle);
    exit(ret);
}

std::string strXor(std::string& s1, std::string& buf, int key)
{
    std::string::string(s1);
    int i = 0;
    
    while (i < s1.size())
    {  
        s1[i] = buf[i] ^ key;
        i++;
    }
    return s1;
}

std::string decode(std::string& bufferIP, std::string argIp)
{
  int key = 170;
  char tmp[48];

  base64_decode(tmp, argIP, 0);
  return strXor(bufferIP, tmp ,key);
}

//----- (0000000140003048) ----------------------------------------------------
int main(int argc, const char **argv)
{
  int h;
  int SystemMetrics;
  char arg1[32];
  char arg2[32];
  char IPAddr[32];
  HDC hdc;

  if (argc == 3)
  {
    decode(arg1, argv[1]);
    if (std::strcmp(arg1, "kwAy93l=="))
    {
      decode(arg2, argv[2]);
      sendPing(arg2);
    }
    else
      displayMsgBox(L"Nice try fellow!");
  }
  hdc = GetDC(0);
  displayMsgBox(L"你好，小龙。你的未来很广阔，你的过去也很狭窄");
  IPAddr = "m5OYhJuckoSbmZiEm56Y";
  std::cout << "*****\n";
  for (int i = 0; i <= 9; ++i )
  {
    h = GetSystemMetrics(1);
    SystemMetrics = GetSystemMetrics(0);
    PatBlt(hdc, 0, 150, SystemMetrics, h, 0xF00021u);
    Sleep(100);
    InvalidateRect(0, 0, 1);
    Sleep(100);
  }
  ReleaseDC(0, hdc);
  relaunchSelf(IPAddr);
  return 0;
}