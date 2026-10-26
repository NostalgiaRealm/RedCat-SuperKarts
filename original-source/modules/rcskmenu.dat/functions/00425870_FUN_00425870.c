/*
 * FUN_00425870 at 00425870
 * undefined __register FUN_00425870(int * param_1, undefined1 param_2)
 * Address ranges: 00425870-004258a3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00425870(int *param_1,undefined1 param_2)

{
  bool bVar1;
  int *piVar2;
  
  *(undefined1 *)(param_1 + 0x7e) = param_2;
  bVar1 = FUN_00445a20((int)param_1);
  if (bVar1) {
    piVar2 = FUN_004298bc(param_1);
    if (piVar2 != (int *)0x0) {
      FUN_004405f0((int)piVar2,0xb007,0,piVar2[0x82]);
    }
  }
  return;
}

