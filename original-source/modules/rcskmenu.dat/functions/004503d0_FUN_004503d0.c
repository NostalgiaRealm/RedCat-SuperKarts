/*
 * FUN_004503d0 at 004503d0
 * undefined __register FUN_004503d0(undefined1 * param_1)
 * Address ranges: 004503d0-004503f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004503d0(undefined1 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = (undefined1)iVar2;
    param_1[2] = uVar1;
    param_1[1] = uVar1;
    *param_1 = uVar1;
    param_1[3] = 0;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 4;
  } while (iVar2 != 0x100);
  return;
}

