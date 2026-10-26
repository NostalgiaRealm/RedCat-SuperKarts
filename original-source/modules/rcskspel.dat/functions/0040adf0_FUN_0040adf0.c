/*
 * FUN_0040adf0 at 0040adf0
 * undefined FUN_0040adf0(void)
 * Address ranges: 0040adf0-0040b07d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0040adf0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar6 = param_1 * 0x11c;
  iVar3 = DAT_006a5c38 +
          *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  iVar4 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
  fVar1 = *(float *)(&DAT_0053f67c + (*(int *)(&DAT_00503f10 + iVar6) + iVar4 * 0x34) * 0x10) -
          *(float *)(iVar3 + 0x50);
  iVar3 = *(int *)(&DAT_00503f10 + iVar6);
  iVar4 = DAT_006a5c38 +
          *(int *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
  iVar5 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
  fVar2 = *(float *)(&DAT_0053f684 + (iVar3 + iVar5 * 0x34) * 0x10) - *(float *)(iVar4 + 0x58);
  fVar1 = SQRT(fVar1 * fVar1 + fVar2 * fVar2);
  if ((_DAT_004debd8 < fVar1) && (fVar1 < 75.0)) {
    _DAT_004debd8 = 3.4028235e+38;
    *(int *)(&DAT_00503f10 + iVar6) = iVar3 + 1;
    iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
    if (*(int *)(&DAT_00503f10 + iVar6) == *(int *)(&DAT_0053f674 + iVar3 * 0x340)) {
      *(undefined4 *)(&DAT_00503f10 + iVar6) = 0xffffffff;
      iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
      if ((&DAT_0053f668)[iVar3 * 0xd0] == 8) {
        (&DAT_00503ef4)[param_1 * 0x47] = 0xe;
      }
      else {
        (&DAT_00503ef4)[param_1 * 0x47] = 3;
      }
    }
  }
  _DAT_004debd8 = fVar1;
  iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
  local_c = *(undefined4 *)(&DAT_0053f67c + (*(int *)(&DAT_00503f10 + iVar6) + iVar3 * 0x34) * 0x10)
  ;
  iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
  local_8 = *(undefined4 *)(&DAT_0053f680 + (*(int *)(&DAT_00503f10 + iVar6) + iVar3 * 0x34) * 0x10)
  ;
  iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
  local_4 = *(undefined4 *)(&DAT_0053f684 + (*(int *)(&DAT_00503f10 + iVar6) + iVar3 * 0x34) * 0x10)
  ;
  iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
  if ((&DAT_0053f668)[iVar3 * 0xd0] == 8) {
    iVar3 = FUN_00444ba0((&DAT_00503f00)[param_1 * 0x47]);
    if (*(int *)(&DAT_00503f10 + iVar6) == *(int *)(&DAT_0053f674 + iVar3 * 0x340) + -1) {
      *(undefined4 *)(&DAT_00503f28 + iVar6) = 0;
      *(undefined4 *)(&DAT_00503f30 + iVar6) = 0;
      *(undefined4 *)(&DAT_00503f2c + iVar6) = 0;
      *(undefined4 *)(&DAT_00503f34 + iVar6) = 1;
      goto LAB_0040b068;
    }
  }
  FUN_004010e0(param_1,&local_c);
LAB_0040b068:
  FUN_00401200(param_1,&local_c);
  return;
}

