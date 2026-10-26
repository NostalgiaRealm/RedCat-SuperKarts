/*
 * FUN_00413ded at 00413ded
 * int * __cdecl FUN_00413ded(LPCSTR param_1, int * param_2, int * param_3, undefined4 param_4, undefined4 * param_5)
 * Address ranges: 00413ded-00413fae
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * __cdecl
FUN_00413ded(LPCSTR param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 *param_5)

{
  FILE *pFVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 in_stack_fffffc4c;
  uint in_stack_fffffc50;
  undefined4 in_stack_fffffc54;
  undefined4 in_stack_fffffc58;
  uint in_stack_fffffc5c;
  uint in_stack_fffffc60;
  uint in_stack_fffffc64;
  char local_388 [768];
  int *local_88;
  char local_84;
  char local_83;
  short local_80;
  short local_7e;
  short local_7c;
  short local_7a;
  short local_42;
  
  puVar3 = param_5;
  puVar4 = (undefined4 *)&stack0xfffffc4c;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_0040e544(in_stack_fffffc4c,in_stack_fffffc50,in_stack_fffffc54,in_stack_fffffc58,
               in_stack_fffffc5c,in_stack_fffffc60,in_stack_fffffc64);
  pFVar1 = (FILE *)FUN_00409d69(param_1);
  if (pFVar1 == (FILE *)0x0) {
    local_88 = (int *)0x0;
  }
  else {
    if (DAT_0043d754 != 0) {
      FUN_00413622((int *)pFVar1,local_388);
    }
    FUN_00409b18((int *)pFVar1,0,0);
    FUN_0041f3be(&local_84,0x80,1,(int *)pFVar1);
    FUN_004015a6((byte *)s__s__d____header_read__00434d9c);
    if ((pFVar1->_flag & 0x20U) == 0) {
      FUN_004015a6((byte *)s__s__d____no_error_header_read__00434dc4);
      if ((local_84 == '\n') && (local_83 == '\x05')) {
        *param_2 = ((int)local_7c - (int)local_80) + 1;
        *param_3 = ((int)local_7a - (int)local_7e) + 1;
        FUN_004015a6((byte *)s_creating_surface__d__d_00434de8);
        local_88 = (int *)FUN_00402e3b(*param_2,*param_3,param_4,param_5);
        FUN_004015a6((byte *)s_creation_succesfull_00434e00);
        FUN_00414f40(local_88,(undefined4 *)pFVar1,(int)local_42,*param_3);
      }
      FUN_004015a6((byte *)s__s__d____closing_00434e24);
      FUN_00409f20(pFVar1);
      FUN_0040e321();
    }
    else {
      FUN_00409f20(pFVar1);
      local_88 = (int *)0x0;
    }
  }
  return local_88;
}

