/*
 * FUN_004161c8 at 004161c8
 * undefined __cdecl FUN_004161c8(int param_1, int param_2, int param_3, int param_4, int param_5, byte * param_6)
 * Address ranges: 004161c8-0041635d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004161c8(int param_1,int param_2,int param_3,int param_4,int param_5,byte *param_6)

{
  int iVar1;
  int iVar2;
  
  DAT_0043db6c = param_2;
  DAT_0043db70 = param_3;
  do {
    while( true ) {
      if (*param_6 == 0) {
        return;
      }
      if ((int)(uint)*param_6 < *(int *)(DAT_0043db88 + 100)) break;
      param_6 = param_6 + 1;
    }
    iVar1 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_6 * 0xc) + 8);
    iVar2 = *(int *)(*(int *)(*(int *)(DAT_0043db88 + 0x68) + (uint)*param_6 * 0xc) + 4);
    if (*param_6 == 9) {
      DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
    }
    else if (*param_6 == 10) {
      if (DAT_0042c354 <= DAT_0043db70 + iVar1 + _DAT_0043db7c) {
        return;
      }
      DAT_0043db70 = DAT_0043db70 + iVar1 + _DAT_0043db7c;
      DAT_0043db6c = 0;
    }
    else {
      if (*(int *)(*(int *)(DAT_0043db88 + 0x68) + 8 + (uint)*param_6 * 0xc) == 1) {
        FUN_00411528(param_1,(uint)*param_6,DAT_0043db6c,DAT_0043db70,param_4,param_5);
      }
      DAT_0043db6c = DAT_0043db6c + iVar2 + _DAT_0043db80;
    }
    param_6 = param_6 + 1;
  } while (DAT_0043db6c <= DAT_0042c350);
  return;
}

