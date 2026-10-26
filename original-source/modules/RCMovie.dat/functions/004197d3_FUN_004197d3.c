/*
 * FUN_004197d3 at 004197d3
 * undefined __cdecl FUN_004197d3(int param_1, undefined4 param_2, char * param_3, size_t param_4)
 * Address ranges: 004197d3-00419838
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __cdecl FUN_004197d3(int param_1,undefined4 param_2,char *param_3,size_t param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_00412b70(param_1);
  iVar2 = FUN_004128fa(param_1);
  if (iVar2 != 7) {
    FUN_0040187a((byte *)s__s__d_____get_ownedit_box_text__c_0043601c);
  }
  _strncpy(param_3,(char *)(iVar1 + 0x50 + *(int *)(iVar1 + 0x30) * 0x65),param_4);
  return;
}

