/*
 * FUN_00408db4 at 00408db4
 * undefined __register FUN_00408db4(short * param_1, ushort * param_2, short * param_3, undefined2 * param_4, undefined4 param_5, undefined4 param_6)
 * Address ranges: 00408db4-00408ef4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00408db4(short *param_1,ushort *param_2,short *param_3,undefined2 *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  uint uVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  short sVar6;
  undefined4 local_1c;
  int local_18;
  short local_14;
  ushort local_12;
  short *local_10;
  ushort *local_c;
  short *local_8;
  
  local_10 = param_3;
  local_c = param_2;
  local_8 = param_1;
  FUN_00408ba4(&local_1c,param_2,param_3,(double)CONCAT44(param_6,param_5));
  if (local_18 < 1) {
    *local_8 = 0;
    *local_c = 0;
    *local_10 = 0;
    *param_4 = 0;
  }
  else {
    *param_4 = (short)(local_18 % 7);
    sVar6 = 1;
    for (uVar5 = local_18 - 1; 0x23ab0 < (int)uVar5; uVar5 = uVar5 - 0x23ab1) {
      sVar6 = sVar6 + 400;
    }
    FUN_00407ba8(uVar5,CONCAT22((short)((uint)(local_18 % 7) >> 0x10),0x8eac),&local_14,&local_12);
    if (local_14 == 4) {
      local_14 = 3;
      local_12 = local_12 + 0x8eac;
    }
    sVar2 = local_14 * 100;
    FUN_00407ba8((uint)local_12,CONCAT22(extraout_var,0x5b5),&local_14,&local_12);
    sVar3 = local_14 * 4;
    FUN_00407ba8((uint)local_12,CONCAT22(extraout_var_00,0x16d),&local_14,&local_12);
    if (local_14 == 4) {
      local_14 = 3;
      local_12 = local_12 + 0x16d;
    }
    sVar6 = sVar6 + sVar2 + sVar3 + local_14;
    uVar5 = FUN_00408cb0(CONCAT22((short)((uint)param_4 >> 0x10),sVar6));
    uVar4 = 1;
    for (; uVar1 = *(ushort *)((uVar5 & 0x7f) * 0x18 + 0x47b0e2 + (uint)uVar4 * 2),
        uVar1 <= local_12; local_12 = local_12 - uVar1) {
      uVar4 = uVar4 + 1;
    }
    *local_8 = sVar6;
    *local_c = uVar4;
    *local_10 = local_12 + 1;
  }
  return;
}

