/*
 * FUN_0048e970 at 0048e970
 * undefined FUN_0048e970(void)
 * Address ranges: 0048e970-0048ea86
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048e970(int *param_1)

{
  float *pfVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  int *piVar5;
  int local_4;
  
  iVar4 = 0;
  local_4 = 0;
  piVar5 = param_1;
  if (0 < param_1[0xe0]) {
    do {
      if (*(char *)((int)piVar5 + 0x11) != '\0') {
        FUN_004afce0(s_HandleSquashedObject__d_004fa298,iVar4);
        DVar3 = GetTickCount();
        iVar2 = piVar5[6];
        if (-1 < piVar5[1]) {
          local_4 = FUN_0042a700(piVar5[1]);
        }
        if ((local_4 == 0) && ((int)(DVar3 - iVar2) <= piVar5[5])) {
          FUN_004afce0(s_HandleSquashedObject_timer_NOT_r_004fa2e4);
          pfVar1 = (float *)(*piVar5 * 0xd0 + 0xa4 + DAT_0067ee20);
          if (*(float *)(*piVar5 * 0xd0 + 0xa4 + DAT_0067ee20) <= DAT_0053ba7c) {
            if (*pfVar1 < DAT_0053ba7c * -1.0) {
              *pfVar1 = DAT_0053ba7c * -1.0;
            }
          }
          else {
            *pfVar1 = DAT_0053ba7c;
          }
          FUN_0048e650(*piVar5);
          if ((char)piVar5[4] != '\0') {
            FUN_0048ea90(iVar4);
          }
        }
        else {
          FUN_004afce0(s_HandleSquashedObject_timer_ready_004fa2b4);
          FUN_0048e840(*piVar5);
        }
        FUN_004afce0(s_HandleSquashedObject_done__004fa318);
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 7;
    } while (iVar4 < param_1[0xe0]);
  }
  return;
}

