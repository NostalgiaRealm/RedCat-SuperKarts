/*
 * FUN_00401140 at 00401140
 * int __cdecl FUN_00401140(uint * param_1, undefined4 param_2)
 * Address ranges: 00401140-00401266
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00401140(uint *param_1,undefined4 param_2)

{
  int iVar1;
  uint **ppuVar2;
  uint *local_600 [128];
  CHAR local_400 [1024];
  
  ppuVar2 = local_600;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar2 = (uint *)0x0;
    ppuVar2 = ppuVar2 + 1;
  }
  local_600[0] = param_1;
  local_600[1] = (uint *)param_2;
  iVar1 = FUN_00405c96(0,param_1,local_600);
  if (iVar1 == -1) {
    switch(DAT_00408c04) {
    case 2:
      FUN_004019af(local_400,0x400,(byte *)s_Could_not_find_file__s___s_004080e4);
      MessageBoxA((HWND)0x0,local_400,s_REDCAT_MOTOR_00408140,0);
      return -1;
    case 7:
      MessageBoxA((HWND)0x0,s_Argument_list_exceeds_1024_bytes_0040811c,s_REDCAT_MOTOR_00408140,0);
      return -1;
    case 8:
      MessageBoxA((HWND)0x0,s_Specified_file_is_not_executable_0040809c,s_REDCAT_MOTOR_00408140,0);
      return -1;
    case 0xc:
      MessageBoxA((HWND)0x0,s_Not_enough_memory_is_available_t_00408064,s_REDCAT_MOTOR_00408140,0);
      break;
    case 0x16:
      MessageBoxA((HWND)0x0,s_Mode_argument_is_invalid_00408100,s_REDCAT_MOTOR_00408140,0);
      return -1;
    }
  }
  return iVar1;
}

