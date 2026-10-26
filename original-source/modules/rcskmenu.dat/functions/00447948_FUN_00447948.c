/*
 * FUN_00447948 at 00447948
 * undefined __register FUN_00447948(int param_1, int param_2, undefined4 * param_3)
 * Address ranges: 00447948-004479bb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447948(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  byte bVar6;
  int local_1c [4];
  
  bVar6 = 0;
  piVar5 = local_1c;
  iVar1 = FUN_004478c8(param_1,param_2,(int)param_3);
  if (iVar1 == 0) {
    FUN_00402b54(param_3,0x10,0);
  }
  else {
    iVar2 = FUN_00447318(iVar1,'\x01');
    iVar3 = FUN_00447318(iVar1,'\x02');
    iVar4 = FUN_004472ac(iVar1,'\x01');
    iVar1 = FUN_004472ac(iVar1,'\x02');
    FUN_0040ec04(iVar1,iVar4,iVar3,piVar5,iVar2);
    piVar5 = local_1c;
    for (iVar1 = 4; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_3 = *piVar5;
      piVar5 = piVar5 + (uint)bVar6 * -2 + 1;
      param_3 = param_3 + (uint)bVar6 * -2 + 1;
    }
  }
  return;
}

