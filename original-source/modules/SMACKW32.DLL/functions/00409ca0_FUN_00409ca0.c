/*
 * FUN_00409ca0 at 00409ca0
 * undefined __thiscall FUN_00409ca0(void * this, int * param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 00409ca0-00409f10
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
FUN_00409ca0(void *this,int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  
  DAT_0040ef00 = param_1;
  DAT_0040ef04 = param_2;
  DAT_0040ef08 = param_3;
  DAT_0040ef0c = param_4;
  DAT_0040ef10 = param_5;
  DAT_0040ef14 = param_6;
  DAT_0040e98c = param_1;
  DAT_0040e990 = param_1 + 0x200;
  DAT_0040e9c0 = 1;
  _DAT_0040e9b0 = 0xb;
  DAT_0040e9b4 = 0x800;
  _DAT_0040e9a4 = param_2;
  FUN_00409c00(this,&DAT_0040e910);
  _DAT_0040e9b0 = 10;
  DAT_0040e9b4 = 0x400;
  FUN_00409c00(extraout_ECX,&DAT_0040e920);
  _DAT_0040e9b0 = 0xc;
  DAT_0040e9b4 = 0x1000;
  FUN_00409c00(extraout_ECX_00,(int *)&DAT_0040e930);
  _DAT_0040e9b0 = 8;
  DAT_0040e9b4 = 0x100;
  FUN_00409c00(extraout_ECX_01,(int *)&DAT_0040e940);
  puVar5 = DAT_0040ef04;
  *DAT_0040ef04 = DAT_0040ef08;
  puVar5[1] = DAT_0040ef0c;
  puVar5[2] = DAT_0040ef10;
  puVar5[3] = DAT_0040ef14;
  puVar4 = &DAT_0040e910;
  puVar5 = puVar5 + 0x1d05;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  piVar7 = DAT_0040ef00;
  for (iVar3 = 0x800; piVar6 = DAT_0040ef00, iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  FUN_00409fe0();
  FUN_00409fe0();
  FUN_00409fe0();
  FUN_00409fe0();
  iVar3 = 0x800;
  do {
    piVar7 = piVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    piVar7 = piVar6 + 1;
    iVar1 = *piVar6;
    piVar6 = piVar7;
  } while (iVar1 == -1);
  uVar2 = piVar7[-1] ^ 0xffffffff;
  iVar3 = 0;
  if (uVar2 != 0) {
    for (; (uVar2 >> iVar3 & 1) == 0; iVar3 = iVar3 + 1) {
    }
  }
  DAT_0040e9d0._0_2_ = ((short)(piVar7 + -1) - (short)DAT_0040ef00) * 8 + (short)iVar3;
  *(short *)(DAT_0040ef04 + 0x1d04) = (short)DAT_0040e9d0;
  FUN_0040a010();
  FUN_0040a010();
  FUN_0040a010();
  FUN_0040a010();
  return;
}

