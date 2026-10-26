/*
 * FUN_00401e74 at 00401e74
 * undefined __register FUN_00401e74(uint * param_1, uint param_2)
 * Address ranges: 00401e74-00401ef8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00401e74(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  
  param_1[2] = param_2;
  *(uint *)((int)param_1 + (param_2 - 4)) = param_2;
  if ((int)param_2 < 0x1001) {
    if ((int)param_2 < 0) {
      param_2 = param_2 + 3;
    }
    puVar1 = *(uint **)(DAT_0047d490 + -0xc + ((int)param_2 >> 2) * 4);
    if (puVar1 == (uint *)0x0) {
      *(uint **)(DAT_0047d490 + -0xc + ((int)param_2 >> 2) * 4) = param_1;
      param_1[1] = (uint)param_1;
      *param_1 = (uint)param_1;
    }
    else {
      uVar2 = *puVar1;
      param_1[1] = (uint)puVar1;
      *param_1 = uVar2;
      *puVar1 = (uint)param_1;
      *(uint **)(uVar2 + 4) = param_1;
    }
  }
  else {
    if ((0x3bff < (int)param_2) && (uVar4 = FUN_00401ddc(param_1,param_2), (char)uVar4 != '\0')) {
      return;
    }
    puVar1 = DAT_0047d484;
    uVar2 = *DAT_0047d484;
    puVar3 = param_1;
    param_1[1] = (uint)DAT_0047d484;
    DAT_0047d484 = puVar3;
    *param_1 = uVar2;
    *puVar1 = (uint)param_1;
    *(uint **)(uVar2 + 4) = param_1;
  }
  return;
}

