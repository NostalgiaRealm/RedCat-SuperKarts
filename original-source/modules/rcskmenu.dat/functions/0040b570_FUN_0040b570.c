/*
 * FUN_0040b570 at 0040b570
 * undefined4 __register FUN_0040b570(undefined * param_1, int param_2)
 * Address ranges: 0040b570-0040b592
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040b570(undefined *param_1,int param_2)

{
  undefined4 uVar1;
  byte *pbVar2;
  
  uVar1 = 0;
  if (DAT_0047d5b8 != '\0') {
    pbVar2 = FUN_00403f94(param_1);
    uVar1 = FUN_0040b4f8(pbVar2,param_2 + -1);
  }
  return uVar1;
}

