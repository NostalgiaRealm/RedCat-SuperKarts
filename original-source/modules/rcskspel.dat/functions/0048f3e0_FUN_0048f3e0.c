/*
 * FUN_0048f3e0 at 0048f3e0
 * undefined FUN_0048f3e0(void)
 * Address ranges: 0048f3e0-0048f4c3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048f3e0(int *param_1)

{
  float fVar1;
  BOOL BVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  LARGE_INTEGER local_8;
  
  if (*param_1 == 0) {
    DVar3 = timeGetTime();
    local_8.s.HighPart = 0;
    local_8.s.LowPart = DVar3;
  }
  else {
    BVar2 = QueryPerformanceCounter(&local_8);
    if (BVar2 == 0) {
      FUN_004afee0(s__s__d_____s_____HiRes_timer_fail_004fa398,
                   s_D__work_rcsk_Code_Engine_Prog_tm_004fa3c0,0x66,s_UpdateTimes_004fa3ec);
      goto LAB_0048f43f;
    }
  }
  param_1[3] = (int)((float)(longlong)local_8 / (float)param_1[1] - (float)param_1[2]);
  param_1[2] = (int)((float)(longlong)local_8 / (float)param_1[1]);
LAB_0048f43f:
  *(int *)(DAT_0067ec28 + DAT_0067ec80 * 4) = param_1[3];
  iVar5 = 2;
  param_1[3] = (int)((float)param_1[3] * 0.5);
  fVar1 = 0.5;
  iVar4 = DAT_0067ec80;
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      iVar4 = 3;
    }
    fVar1 = fVar1 * 0.5;
    iVar5 = iVar5 + -1;
    param_1[3] = (int)(fVar1 * *(float *)(DAT_0067ec28 + iVar4 * 4) + (float)param_1[3]);
  } while (iVar5 != 0);
  iVar4 = iVar4 + -1;
  if (iVar4 < 0) {
    iVar4 = 3;
  }
  param_1[3] = (int)(fVar1 * *(float *)(DAT_0067ec28 + iVar4 * 4) + (float)param_1[3]);
  DAT_0067ec80 = DAT_0067ec80 + 1;
  if (3 < DAT_0067ec80) {
    DAT_0067ec80 = 0;
  }
  return;
}

