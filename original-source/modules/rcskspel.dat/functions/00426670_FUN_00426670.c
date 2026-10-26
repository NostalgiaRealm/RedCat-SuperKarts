/*
 * FUN_00426670 at 00426670
 * undefined FUN_00426670(void)
 * Address ranges: 00426670-00426716
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426670(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [16];
  
  puVar2 = (undefined4 *)
           (DAT_006a5c38 + *(int *)(param_1 * 0xd0 + 0xc + DAT_0067ee20) * 0xa9 + 0x10);
  puVar3 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_004265e0(param_1,param_2,local_40,2,0x40800000);
  FUN_004265e0(param_1,param_2 + 0x20,local_40,2,0xc0800000);
  FUN_004265e0(param_1,param_3,local_40,3,0x40800000);
  FUN_004265e0(param_1,param_3 + 0x20,local_40,3,0xc0800000);
  return;
}

