/*
 * FUN_00412390 at 00412390
 * undefined FUN_00412390(void)
 * Address ranges: 00412390-004123ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00412390(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  float10 fVar7;
  
  piVar3 = param_2;
  fVar7 = (float10)FUN_0048f4e0();
  fVar2 = (float)param_2[0x26];
  param_2[0x26] = (int)(float)((float10)fVar2 - fVar7);
  if ((float10)fVar2 - fVar7 <= (float10)0.0) {
    FUN_00412330(param_2);
    return 0;
  }
  uVar4 = FUN_0040c8f0();
  uVar5 = FUN_0040c900();
  iVar6 = FUN_0040c970();
  param_2 = (int *)0x3f800000;
  if (iVar6 != 0) {
    param_2 = (int *)0xbf800000;
  }
  FUN_0040c990();
  FUN_00456aa0(uVar4,uVar5);
  FUN_0040c980();
  FUN_0040c9a0();
  fVar7 = (float10)FUN_00456aa0(uVar4,uVar5);
  puVar1 = (undefined4 *)(*piVar3 * 0xd0 + 0x9c + DAT_0067ee20);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  *(float *)(*piVar3 * 0xd0 + 0xac + DAT_0067ee20) =
       (float)(((float10)6.5 / fVar7) * (float10)(float)param_2);
  iVar6 = FUN_0040c970();
  if (iVar6 == 0) {
    FUN_0040c990();
  }
  else {
    FUN_00417e90(param_1);
    FUN_0040c990();
  }
  iVar6 = __ftol();
  if (0 < iVar6) {
    FUN_00412330(piVar3);
    return 0;
  }
  return 1;
}

