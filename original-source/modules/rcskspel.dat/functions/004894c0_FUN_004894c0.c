/*
 * FUN_004894c0 at 004894c0
 * undefined FUN_004894c0(void)
 * Address ranges: 004894c0-004895c1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall
FUN_004894c0(int param_1,int param_2,undefined4 *param_3,char param_4,int param_5,char param_6,
            undefined1 param_7,float param_8,char param_9,undefined1 param_10)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  *(int *)(param_1 + 0xe8) = param_2;
  *(undefined1 *)(param_1 + 0xec) = 1;
  *(undefined4 *)(param_1 + 0xf0) = *param_3;
  *(undefined4 *)(param_1 + 0xf4) = param_3[1];
  uVar1 = param_3[2];
  *(undefined1 *)(param_1 + 0x11c) = param_10;
  *(undefined4 *)(param_1 + 0xf8) = uVar1;
  *(char *)(param_1 + 0x101) = param_6;
  *(int *)(param_1 + 0xfc) = param_5;
  if (param_6 == '\0') {
    if (((param_5 < 6) || (param_5 = param_5 + -6, param_5 < 6)) && (-1 < param_5)) {
      *(int *)(param_1 + 0xfc) = param_5;
    }
    else {
      *(undefined4 *)(param_1 + 0xfc) = 0;
    }
  }
  *(undefined1 *)(param_1 + 0x102) = param_7;
  *(char *)(param_1 + 0x100) = param_4;
  if (param_4 != '\0') {
    *(undefined1 *)(param_1 + 0x102) = 1;
  }
  *(float *)(param_1 + 0x104) = param_8;
  *(char *)(param_1 + 0x108) = param_9;
  if (param_9 != '\0') {
    _param_6 = param_8;
    if (param_2 != DAT_0053be28) {
      _param_6 = param_8 * 2.5;
    }
    param_5 = param_5 + 1;
    uVar3 = 0;
    uVar2 = 0;
    uVar1 = 1;
    FUN_00488a90(param_2,param_3,1,param_5,0,0,_param_6);
    FUN_00488b80(param_2,param_3,uVar1,param_5,uVar2,uVar3,_param_6);
  }
  DAT_00545108 = FUN_004a6060(s_S_SFX_PCX_004f9f24);
  return;
}

