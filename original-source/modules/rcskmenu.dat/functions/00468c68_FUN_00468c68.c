/*
 * FUN_00468c68 at 00468c68
 * undefined __register FUN_00468c68(undefined4 * param_1, int * param_2)
 * Address ranges: 00468c68-00468cb4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00468c68(undefined4 *param_1,int *param_2)

{
  byte *pbVar1;
  undefined *puVar2;
  int iVar3;
  
  FUN_00403ba4(param_2,param_1);
  pbVar1 = FUN_00408144((undefined *)*param_2);
  while( true ) {
    iVar3 = FUN_00403dd0(*param_2);
    if ((iVar3 < 1) || ((0x20 < *pbVar1 && (*pbVar1 != 0x2e)))) break;
    puVar2 = FUN_00403f94((undefined *)*param_2);
    FUN_00404104(param_2,(int)pbVar1 - (int)puVar2);
    pbVar1 = FUN_00408144((undefined *)*param_2);
  }
  return;
}

