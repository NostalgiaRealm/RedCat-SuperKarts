/*
 * FUN_00458490 at 00458490
 * int __register FUN_00458490(int param_1, undefined2 * param_2, int param_3)
 * Address ranges: 00458490-004584ae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00458490(int param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = -1;
  if ((-1 < param_3) && (param_3 < 0x1e)) {
    *param_2 = *(undefined2 *)(param_1 + 4 + param_3 * 2);
    iVar1 = param_3;
  }
  return iVar1;
}

