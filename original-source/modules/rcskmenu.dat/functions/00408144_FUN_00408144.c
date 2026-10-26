/*
 * FUN_00408144 at 00408144
 * undefined * __register FUN_00408144(undefined * param_1)
 * Address ranges: 00408144-00408171
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined * FUN_00408144(undefined *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  iVar1 = FUN_00403dd0((int)param_1);
  if (iVar1 == 0) {
    puVar3 = (undefined *)0x0;
  }
  else {
    puVar3 = param_1 + iVar1 + -1;
    uVar2 = FUN_0040b570(param_1,iVar1);
    if ((char)uVar2 == '\x02') {
      puVar3 = puVar3 + -1;
    }
  }
  return puVar3;
}

