/*
 * _SmackSummary@8 at 00403f50
 * undefined __stdcall _SmackSummary@8(int param_1, int * param_2)
 * Address ranges: 00403f50-00404051
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void _SmackSummary_8(int param_1,int *param_2)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x3f50  20  _SmackSummary@8 */
  FUN_00404060();
  DVar1 = timeGetTime();
  *param_2 = DVar1 - *(int *)(param_1 + 0x46c);
  param_2[1] = *(int *)(param_1 + 0x400);
  param_2[2] = *(int *)(param_1 + 0x470);
  param_2[3] = *(int *)(param_1 + 0x478);
  param_2[4] = *(int *)(param_1 + 0x47c);
  param_2[5] = *(int *)(param_1 + 0x480);
  param_2[6] = *(int *)(param_1 + 0x44c) - *(int *)(param_1 + 0x474);
  param_2[8] = *(int *)(param_1 + 0x454);
  param_2[7] = *(int *)(param_1 + 0x484);
  uVar3 = *(int *)(param_1 + 0x454) + *(int *)(param_1 + 0x44c);
  if (uVar3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (int)(((ulonglong)(uint)(*(int *)(param_1 + 0x448) + *(int *)(param_1 + 0x450)) * 1000)
                 / (ulonglong)uVar3);
  }
  param_2[9] = iVar2;
  param_2[10] = *(int *)(param_1 + 0x488);
  param_2[0xc] = *(int *)(param_1 + 0x490) + 1;
  param_2[0xb] = *(int *)(param_1 + 0x48c);
  param_2[0xd] = *(int *)(param_1 + 0x494) + 1;
  param_2[0xe] = *(int *)(param_1 + 0x498);
  param_2[0x11] = *(int *)(param_1 + 0x49c);
  param_2[0x12] = *(int *)(param_1 + 0x440);
  param_2[0x13] = *(int *)(param_1 + 0x458);
  param_2[0xf] = *(int *)(param_1 + 0x4a4);
  param_2[0x10] = *(int *)(param_1 + 0x4a8) + 1;
  return;
}

