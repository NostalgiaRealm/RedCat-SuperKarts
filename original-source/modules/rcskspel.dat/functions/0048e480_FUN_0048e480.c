/*
 * FUN_0048e480 at 0048e480
 * undefined FUN_0048e480(void)
 * Address ranges: 0048e480-0048e534
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048e480(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *local_4;
  
  *param_1 = DAT_0053be28;
  param_1[1] = 0x13;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  param_1[3] = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  param_1[2] = 0;
  *(undefined1 *)((int)param_1 + 0x12) = 1;
  param_1[5] = DAT_0053ba88;
  iVar4 = 0;
  if (0 < DAT_00508610) {
    local_4 = &DAT_005081bc;
    piVar3 = param_1 + 8;
    do {
      cVar1 = FUN_00417e90(iVar4);
      iVar2 = DAT_0053be28;
      if (cVar1 == '\0') {
        iVar2 = *local_4;
      }
      piVar3[-1] = iVar2;
      *piVar3 = iVar4 + 0x14;
      *(undefined1 *)((int)piVar3 + 0xd) = 0;
      piVar3[2] = 0;
      *(undefined1 *)(piVar3 + 3) = 0;
      piVar3[1] = 0;
      *(undefined1 *)((int)piVar3 + 0xe) = 1;
      piVar3[4] = DAT_0053ba88;
      FUN_00417e90(iVar4);
      local_4 = local_4 + 0x1c;
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 7;
    } while (iVar4 < DAT_00508610);
  }
  param_1[0xe0] = DAT_00508610 + 1;
  FUN_0048e260();
  return;
}

