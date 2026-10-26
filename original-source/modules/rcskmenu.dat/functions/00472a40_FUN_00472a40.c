/*
 * FUN_00472a40 at 00472a40
 * undefined __register FUN_00472a40(int param_1, undefined4 param_2)
 * Address ranges: 00472a40-00472af8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00472a40(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar6;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_c;
  uint *local_8;
  
  puStack_1c = &stack0xfffffffc;
  local_8 = (uint *)0x0;
  local_c = (undefined4 *)0x0;
  puStack_20 = &LAB_00472af9;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  FUN_00407f60(param_2,(int *)&local_c);
  FUN_00403e1c((int *)&local_8,(undefined4 *)"imgFinPos",local_c);
  iVar1 = FUN_0044268c(param_1);
  if ((0 < iVar1) && (iVar1 = FUN_0044268c(param_1), -1 < iVar1 + -1)) {
    iVar5 = 0;
    uVar6 = true;
    do {
      iVar2 = FUN_00442650(param_1,iVar5);
      FUN_00403ee0(*(uint **)(iVar2 + 8),local_8);
      if ((bool)uVar6) {
        piVar3 = (int *)FUN_00442650(param_1,iVar5);
        uVar4 = FUN_00403024(piVar3,(int)&PTR_FUN_004536f0);
        if ((char)uVar4 != '\0') {
          piVar3 = (int *)FUN_00442650(param_1,iVar5);
          FUN_0040303c(piVar3,(int)&PTR_FUN_004536f0);
          break;
        }
      }
      iVar5 = iVar5 + 1;
      iVar1 = iVar1 + -1;
      uVar6 = iVar1 == 0;
    } while (!(bool)uVar6);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00472b00;
  puStack_20 = (undefined1 *)0x472af8;
  FUN_00403b74((int *)&local_c,2);
  return;
}

