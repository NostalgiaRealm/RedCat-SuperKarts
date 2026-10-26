/*
 * FUN_0048e780 at 0048e780
 * undefined FUN_0048e780(void)
 * Address ranges: 0048e780-0048e832
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0048e780(int param_1)

{
  float *pfVar1;
  int iVar2;
  DWORD DVar3;
  
  iVar2 = FUN_0048e740(param_1);
  if ((iVar2 != 0) && (*(char *)(iVar2 + 0x11) == '\0')) {
    *(undefined1 *)(iVar2 + 0x11) = 1;
    *(undefined1 *)(iVar2 + 0x10) = *(undefined1 *)(iVar2 + 0x12);
    FUN_0048e650(param_1);
    pfVar1 = (float *)(param_1 * 0xd0 + 0xa4 + DAT_0067ee20);
    if (*(float *)(param_1 * 0xd0 + 0xa4 + DAT_0067ee20) <= DAT_0053ba7c) {
      if (*pfVar1 < DAT_0053ba7c * -1.0) {
        *pfVar1 = DAT_0053ba7c * -1.0;
      }
    }
    else {
      *pfVar1 = DAT_0053ba7c;
    }
    DVar3 = GetTickCount();
    *(DWORD *)(iVar2 + 0x18) = DVar3;
    if (-1 < *(int *)(iVar2 + 4)) {
      FUN_0042a670(*(int *)(iVar2 + 4),*(undefined4 *)(iVar2 + 0x14),1);
      FUN_0042a210(*(undefined4 *)(iVar2 + 4));
    }
  }
  return;
}

