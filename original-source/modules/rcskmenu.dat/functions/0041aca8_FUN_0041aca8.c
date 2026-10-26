/*
 * FUN_0041aca8 at 0041aca8
 * undefined __register FUN_0041aca8(undefined4 param_1, int * param_2)
 * Address ranges: 0041aca8-0041ace1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041aca8(undefined4 param_1,int *param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  pcVar3 = FUN_0041aab8;
  puVar2 = &LAB_0041abd0;
  uVar4 = param_1;
  bVar1 = FUN_0041ac2c();
  (**(code **)(*param_2 + 8))(param_2,&DAT_0041acec,bVar1,puVar2,param_1,pcVar3,uVar4);
  return;
}

