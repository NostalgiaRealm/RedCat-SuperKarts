/*
 * FUN_0044f8e0 at 0044f8e0
 * undefined FUN_0044f8e0(void)
 * Address ranges: 0044f8e0-0044f98b
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0044f8e0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  
  FUN_0044f110();
  if (*(int *)(param_1 + 0x60) != 0) {
    puVar3 = *(undefined1 **)(param_1 + 8);
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_004d2404;
    }
    FUN_0044f500();
    uVar1 = FUN_0044e960();
    FUN_004afce0(s__s__d_004f0f30,puVar3,uVar1);
    FUN_0044f500();
    iVar2 = DAT_006a5c38 + *(int *)(*(int *)(param_1 + 0x68) * 0xd0 + 0xc + DAT_0067ee20) * 0xa9;
    FUN_0044f500();
    uVar1 = FUN_0044e960();
    uVar1 = FUN_0044ebb0(uVar1);
    *(undefined4 *)(iVar2 + 0x99) = uVar1;
  }
  return;
}

