/*
 * FUN_0048f520 at 0048f520
 * undefined FUN_0048f520(void)
 * Address ranges: 0048f520-0048f5a5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048f520(int *param_1)

{
  ulonglong uVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  LARGE_INTEGER local_8;
  
  if (*param_1 == 0) {
    DVar3 = timeGetTime();
    uVar1 = (ulonglong)DVar3;
  }
  else {
    BVar2 = QueryPerformanceCounter(&local_8);
    if (BVar2 == 0) {
      FUN_004afee0(s__s__d_____s_____HiRes_timer_fail_004fa398,
                   s_D__work_rcsk_Code_Engine_Prog_tm_004fa3c0,0xd1,s_reset_004fa3f8);
      goto LAB_0048f582;
    }
    uVar1 = CONCAT44(local_8.s.HighPart,local_8.s.LowPart);
  }
  param_1[3] = (int)((float)(longlong)uVar1 / (float)param_1[1] - (float)param_1[2]);
  param_1[2] = (int)((float)(longlong)uVar1 / (float)param_1[1]);
LAB_0048f582:
  iVar4 = 0;
  do {
    iVar5 = iVar4 + 4;
    *(undefined4 *)(iVar4 + DAT_0067ec28) = 0x3dcccccd;
    iVar4 = iVar5;
  } while (iVar5 < 0x10);
  param_1[3] = 0;
  return;
}

