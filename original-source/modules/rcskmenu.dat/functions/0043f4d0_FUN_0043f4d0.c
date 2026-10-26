/*
 * FUN_0043f4d0 at 0043f4d0
 * undefined __register FUN_0043f4d0(int * param_1, int * param_2)
 * Address ranges: 0043f4d0-0043f514
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043f4d0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [8];
  int iStack_14;
  int iStack_10;
  
  iVar1 = *param_2;
  iVar2 = param_2[1];
  (**(code **)(*param_1 + 0x40))(param_1,local_1c,*param_1,iVar1,iVar2);
  (**(code **)(*param_1 + 0x7c))
            (param_1,param_1[0xc],param_1[0xd],(param_1[0xf] - iStack_10) + iVar2,
             (param_1[0xe] - iStack_14) + iVar1);
  return;
}

