/*
 * FUN_00412978 at 00412978
 * undefined __register FUN_00412978(int param_1)
 * Address ranges: 00412978-004129b1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00412978(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 4) + 4))
                    (*(int **)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                     *(undefined4 *)(param_1 + 0xc));
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 == 0) {
    piVar2 = FUN_0040ad20((int *)&DAT_0040dadc,'\x01',(undefined4 *)PTR_PTR_0047c960);
    FUN_00403604(piVar2);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

