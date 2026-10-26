/*
 * FUN_00415e91 at 00415e91
 * undefined __cdecl FUN_00415e91(int param_1, byte * param_2)
 * Address ranges: 00415e91-0041603b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00415e91(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  while (*param_2 != 0) {
    if ((int)(uint)*param_2 < *(int *)(DAT_0043db88 + 100)) {
      iVar1 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_2 * 0xc) + 8);
      iVar2 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_2 * 0xc) + 4);
      if (*param_2 == 9) {
        DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
      }
      else if (*param_2 == 10) {
        if (DAT_0043db70 + iVar1 + _DAT_0043db7c < DAT_0042c354) {
          DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
        }
        DAT_0043db6c = 0;
      }
      else {
        if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + (uint)*param_2 * 0xc) == 1) {
          FUN_00411068(param_1,(uint)*param_2,DAT_0043db6c,DAT_0043db70);
        }
        DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
      }
      param_2 = param_2 + 1;
      if (DAT_0042c350 < DAT_0043db6c) {
        if (DAT_0043db70 + iVar1 + _DAT_0043db7c < DAT_0042c354) {
          DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
        }
        DAT_0043db6c = 0;
      }
    }
    else {
      param_2 = param_2 + 1;
    }
  }
  return;
}

