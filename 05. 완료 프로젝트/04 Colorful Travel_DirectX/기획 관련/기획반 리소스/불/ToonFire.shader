// Made with Amplify Shader Editor
// Available at the Unity Asset Store - http://u3d.as/y3X 
Shader "Toon Fire"
{
	Properties
	{
		_Cutoff( "Mask Clip Value", Float ) = 0.5
		_Mask("Mask", 2D) = "white" {}
		_Noize("Noize", 2D) = "white" {}
		_Color1("Color 1", Color) = (0.9921569,0.7561098,0,0)
		_Color2("Color 2", Color) = (0.9607843,0.8874567,0.05098042,0)
		_Color3("Color 3", Color) = (0.9528302,0.2721055,0.08539513,0)
		_ColorBlend("Color Blend", Range( 0 , 1)) = 0.5270881
		_Speed1("Speed 1", Float) = -1.5
		_Scale1("Scale 1", Float) = 1.22
		_Speed2("Speed 2", Float) = -1
		_Scale2("Scale 2", Float) = 0.52
		_Emission("Emission", Float) = 0
		[HideInInspector] _texcoord( "", 2D ) = "white" {}
		[HideInInspector] __dirty( "", Int ) = 1
	}

	SubShader
	{
		Tags{ "RenderType" = "TransparentCutout"  "Queue" = "Geometry+0" "IsEmissive" = "true"  }
		Cull Back
		CGPROGRAM
		#include "UnityShaderVariables.cginc"
		#pragma target 3.0
		#pragma surface surf Standard keepalpha addshadow fullforwardshadows 
		struct Input
		{
			float2 uv_texcoord;
		};

		uniform float _Emission;
		uniform sampler2D _Noize;
		uniform float _Speed1;
		uniform float _Scale1;
		uniform float _Speed2;
		uniform float _Scale2;
		uniform sampler2D _Mask;
		uniform float4 _Mask_ST;
		uniform float4 _Color1;
		uniform float4 _Color2;
		uniform float _ColorBlend;
		uniform float4 _Color3;
		uniform float _Cutoff = 0.5;

		void surf( Input i , inout SurfaceOutputStandard o )
		{
			float3 temp_cast_0 = (0.6553948).xxx;
			float4 appendResult9 = (float4(0.0 , _Speed1 , 0.0 , 0.0));
			float2 uv_TexCoord16 = i.uv_texcoord * float2( 1.5,1 );
			float2 panner10 = ( 1.0 * _Time.y * appendResult9.xy + ( _Scale1 * uv_TexCoord16 ));
			float4 appendResult17 = (float4(0.0 , _Speed2 , 0.0 , 0.0));
			float2 panner11 = ( 1.0 * _Time.y * appendResult17.xy + ( uv_TexCoord16 * _Scale2 ));
			float2 uv_Mask = i.uv_texcoord * _Mask_ST.xy + _Mask_ST.zw;
			float3 desaturateInitialColor35 = ( ( tex2D( _Noize, panner10 ) * tex2D( _Noize, panner11 ) ) * tex2D( _Mask, uv_Mask ) ).rgb;
			float desaturateDot35 = dot( desaturateInitialColor35, float3( 0.299, 0.587, 0.114 ));
			float3 desaturateVar35 = lerp( desaturateInitialColor35, desaturateDot35.xxx, 1.0 );
			float3 temp_output_24_0 = step( temp_cast_0 , desaturateVar35 );
			float3 temp_cast_5 = (0.3997816).xxx;
			float3 temp_cast_6 = (0.6553948).xxx;
			float3 temp_output_34_0 = ( step( temp_cast_5 , desaturateVar35 ) - temp_output_24_0 );
			float smoothstepResult68 = smoothstep( 0.0 , _ColorBlend , i.uv_texcoord.y);
			o.Emission = ( _Emission * ( ( float4( temp_output_24_0 , 0.0 ) * _Color1 ) + ( float4( temp_output_34_0 , 0.0 ) * ( ( _Color2 * ( 1.0 - smoothstepResult68 ) ) + ( smoothstepResult68 * _Color3 ) ) ) ) ).rgb;
			o.Alpha = 1;
			float3 temp_cast_9 = (0.3997816).xxx;
			float3 temp_cast_10 = (0.6553948).xxx;
			float3 temp_cast_11 = (0.6553948).xxx;
			clip( ( temp_output_34_0 + temp_output_24_0 ).x - _Cutoff );
		}

		ENDCG
	}
	Fallback "Diffuse"
	CustomEditor "ASEMaterialInspector"
}
/*ASEBEGIN
Version=18500
8;81;1172;910;1060.686;625.0142;1.975561;False;False
Node;AmplifyShaderEditor.CommentaryNode;42;-3815.541,-291.2739;Inherit;False;2212.41;837.3931;Noize;18;12;14;16;15;13;18;8;17;9;11;10;3;5;6;20;7;19;35;;1,1,1,1;0;0
Node;AmplifyShaderEditor.RangedFloatNode;14;-3703.54,-37.44666;Inherit;False;Property;_Scale1;Scale 1;8;0;Create;True;0;0;False;0;False;1.22;1.22;0;0;0;1;FLOAT;0
Node;AmplifyShaderEditor.RangedFloatNode;13;-3664.541,298.5533;Inherit;False;Property;_Speed2;Speed 2;9;0;Create;True;0;0;False;0;False;-1;-1;0;0;0;1;FLOAT;0
Node;AmplifyShaderEditor.RangedFloatNode;12;-3737.263,-233.9059;Inherit;False;Property;_Speed1;Speed 1;7;0;Create;True;0;0;False;0;False;-1.5;-1.52;0;0;0;1;FLOAT;0
Node;AmplifyShaderEditor.TextureCoordinatesNode;16;-3765.541,37.5534;Inherit;False;0;-1;2;3;2;SAMPLER2D;;False;0;FLOAT2;1.5,1;False;1;FLOAT2;0,0;False;5;FLOAT2;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.RangedFloatNode;15;-3678.541,224.5535;Inherit;False;Property;_Scale2;Scale 2;10;0;Create;True;0;0;False;0;False;0.52;0.52;0;0;0;1;FLOAT;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;8;-3431.722,-71.07406;Inherit;False;2;2;0;FLOAT;0;False;1;FLOAT2;0,0;False;1;FLOAT2;0
Node;AmplifyShaderEditor.DynamicAppendNode;9;-3423.424,-241.2739;Inherit;False;FLOAT4;4;0;FLOAT;0;False;1;FLOAT;0;False;2;FLOAT;0;False;3;FLOAT;0;False;1;FLOAT4;0
Node;AmplifyShaderEditor.DynamicAppendNode;17;-3423.541,296.5533;Inherit;False;FLOAT4;4;0;FLOAT;0;False;1;FLOAT;0;False;2;FLOAT;0;False;3;FLOAT;0;False;1;FLOAT4;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;18;-3418.541,88.55338;Inherit;False;2;2;0;FLOAT2;0,0;False;1;FLOAT;0;False;1;FLOAT2;0
Node;AmplifyShaderEditor.TexturePropertyNode;3;-3043.001,49.47963;Inherit;True;Property;_Noize;Noize;2;0;Create;True;0;0;False;0;False;12bb264af805fb64bae78faa2a500f26;12bb264af805fb64bae78faa2a500f26;False;white;Auto;Texture2D;-1;0;2;SAMPLER2D;0;SAMPLERSTATE;1
Node;AmplifyShaderEditor.PannerNode;11;-3032.58,332.6011;Inherit;False;3;0;FLOAT2;0,0;False;2;FLOAT2;0,0;False;1;FLOAT;1;False;1;FLOAT2;0
Node;AmplifyShaderEditor.PannerNode;10;-3053.552,-221.3349;Inherit;False;3;0;FLOAT2;0,0;False;2;FLOAT2;0,0;False;1;FLOAT;1;False;1;FLOAT2;0
Node;AmplifyShaderEditor.CommentaryNode;40;-303.1252,-134.5114;Inherit;False;1587.272;1319.2;Color;5;38;36;37;27;74;;1,1,1,1;0;0
Node;AmplifyShaderEditor.SamplerNode;5;-2708.476,-24.69457;Inherit;True;Property;_TextureSample0;Texture Sample 0;1;0;Create;True;0;0;False;0;False;-1;None;None;True;0;False;white;Auto;False;Object;-1;Auto;Texture2D;8;0;SAMPLER2D;;False;1;FLOAT2;0,0;False;2;FLOAT;0;False;3;FLOAT2;0,0;False;4;FLOAT2;0,0;False;5;FLOAT;1;False;6;FLOAT;0;False;7;SAMPLERSTATE;;False;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SamplerNode;6;-2718.624,186.3664;Inherit;True;Property;_TextureSample1;Texture Sample 1;1;0;Create;True;0;0;False;0;False;-1;None;None;True;0;False;white;Auto;False;Object;-1;Auto;Texture2D;8;0;SAMPLER2D;;False;1;FLOAT2;0,0;False;2;FLOAT;0;False;3;FLOAT2;0,0;False;4;FLOAT2;0,0;False;5;FLOAT;1;False;6;FLOAT;0;False;7;SAMPLERSTATE;;False;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SamplerNode;20;-2391.121,316.1192;Inherit;True;Property;_Mask;Mask;1;0;Create;True;0;0;False;0;False;-1;186c8409f5785a847a92b9d30a492597;186c8409f5785a847a92b9d30a492597;True;0;False;white;Auto;False;Object;-1;Auto;Texture2D;8;0;SAMPLER2D;;False;1;FLOAT2;0,0;False;2;FLOAT;0;False;3;FLOAT2;0,0;False;4;FLOAT2;0,0;False;5;FLOAT;1;False;6;FLOAT;0;False;7;SAMPLERSTATE;;False;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;7;-2339.342,80.61156;Inherit;True;2;2;0;COLOR;0,0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.CommentaryNode;74;-285.0155,512.0834;Inherit;False;1531.736;649.6945;outer color;9;72;73;71;70;68;69;66;67;28;;1,1,1,1;0;0
Node;AmplifyShaderEditor.TextureCoordinatesNode;69;-206.8953,725.2357;Inherit;False;0;-1;2;3;2;SAMPLER2D;;False;0;FLOAT2;1,1;False;1;FLOAT2;0,0;False;5;FLOAT2;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.RangedFloatNode;67;-257.8952,875.2357;Inherit;False;Property;_ColorBlend;Color Blend;6;0;Create;True;0;0;False;0;False;0.5270881;0.5270881;0;1;0;1;FLOAT;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;19;-2017.123,130.1191;Inherit;True;2;2;0;COLOR;0,0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.CommentaryNode;41;-1485.132,-46.22875;Inherit;False;1155.007;562.9855;Step;7;33;32;31;23;24;34;39;;1,1,1,1;0;0
Node;AmplifyShaderEditor.SmoothstepOpNode;68;24.05574,759.5247;Inherit;False;3;0;FLOAT;0;False;1;FLOAT;0;False;2;FLOAT;1;False;1;FLOAT;0
Node;AmplifyShaderEditor.DesaturateOpNode;35;-1803.132,129.706;Inherit;False;2;0;FLOAT3;0,0,0;False;1;FLOAT;1;False;1;FLOAT3;0
Node;AmplifyShaderEditor.RangedFloatNode;32;-1430.409,3.77125;Inherit;False;Constant;_Float1;Float 1;8;0;Create;True;0;0;False;0;False;0.6553948;0;0;1;0;1;FLOAT;0
Node;AmplifyShaderEditor.ColorNode;66;-253.8952,947.2357;Inherit;False;Property;_Color3;Color 3;5;0;Create;True;0;0;False;0;False;0.9528302,0.2721055,0.08539513,0;0.9528301,0.2721054,0.08539511,0;True;0;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.ColorNode;28;-243.6219,541.7878;Inherit;False;Property;_Color2;Color 2;4;0;Create;True;0;0;False;0;False;0.9607843,0.8874567,0.05098042,0;1,0.8992966,0.4009433,0;True;0;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.OneMinusNode;70;195.9027,690.9028;Inherit;False;1;0;FLOAT;0;False;1;FLOAT;0
Node;AmplifyShaderEditor.RelayNode;33;-1415.99,126.5442;Inherit;False;1;0;FLOAT3;0,0,0;False;1;FLOAT3;0
Node;AmplifyShaderEditor.RangedFloatNode;31;-1435.132,372.6863;Inherit;False;Constant;_Float0;Float 0;8;0;Create;True;0;0;False;0;False;0.3997816;0;0;1;0;1;FLOAT;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;71;183.4695,945.0939;Inherit;False;2;2;0;FLOAT;0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.StepOpNode;23;-1091.622,248.7131;Inherit;True;2;0;FLOAT;0;False;1;FLOAT3;0.8207547,0.8207547,0.8207547;False;1;FLOAT3;0
Node;AmplifyShaderEditor.StepOpNode;24;-1088.428,32.00523;Inherit;True;2;0;FLOAT;20;False;1;FLOAT3;0.4716981,0.4716981,0.4716981;False;1;FLOAT3;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;73;397.5986,653.6031;Inherit;False;2;2;0;COLOR;0,0,0,0;False;1;FLOAT;0;False;1;COLOR;0
Node;AmplifyShaderEditor.SimpleSubtractOpNode;34;-748.497,271.7567;Inherit;True;2;0;FLOAT3;0,0,0;False;1;FLOAT3;0,0,0;False;1;FLOAT3;0
Node;AmplifyShaderEditor.ColorNode;27;361.5976,-92.13805;Inherit;False;Property;_Color1;Color 1;3;0;Create;True;0;0;False;0;False;0.9921569,0.7561098,0,0;0.8396226,0.6172442,0.4237717,0;True;0;5;COLOR;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SimpleAddOpNode;72;533.7842,701.857;Inherit;True;2;2;0;COLOR;0,0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;37;704.9307,268.1764;Inherit;True;2;2;0;FLOAT3;0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.CommentaryNode;51;127.9123,1194.47;Inherit;False;1119.6;818.8315;Comment;8;49;50;48;46;47;45;58;57;;1,1,1,1;0;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;36;684.9307,52.17635;Inherit;True;2;2;0;FLOAT3;0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.SimpleAddOpNode;38;972.8796,164.5826;Inherit;True;2;2;0;COLOR;0,0,0,0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.CommentaryNode;57;366.3332,1628.24;Inherit;False;630.5754;376.1078;Comment;5;52;53;56;55;54;Billboard;1,1,1,1;0;0
Node;AmplifyShaderEditor.RangedFloatNode;64;1305.641,66.28424;Inherit;False;Property;_Emission;Emission;12;0;Create;True;0;0;False;0;False;0;2;0;0;0;1;FLOAT;0
Node;AmplifyShaderEditor.PosVertexDataNode;53;417.612,1821.348;Inherit;False;0;0;5;FLOAT3;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.RangedFloatNode;54;664.1412,1678.24;Inherit;False;Constant;_Float3;Float 3;10;0;Create;True;0;0;False;0;False;0.1;0;0;0;0;1;FLOAT;0
Node;AmplifyShaderEditor.RangedFloatNode;50;475.8421,1244.471;Inherit;False;Property;_PushForward;Push Forward;11;0;Create;True;0;0;False;0;False;0;0.449;0;0.5;0;1;FLOAT;0
Node;AmplifyShaderEditor.BillboardNode;52;416.3329,1724.004;Inherit;False;Cylindrical;False;0;1;FLOAT3;0
Node;AmplifyShaderEditor.SimpleSubtractOpNode;46;527.613,1352.698;Inherit;False;2;0;FLOAT3;0,0,0;False;1;FLOAT4;0,0,0,0;False;1;FLOAT4;0
Node;AmplifyShaderEditor.WorldSpaceCameraPos;47;177.9125,1247.398;Inherit;False;0;4;FLOAT3;0;FLOAT;1;FLOAT;2;FLOAT;3
Node;AmplifyShaderEditor.ObjectToWorldTransfNode;45;228.4357,1408.302;Inherit;False;1;0;FLOAT4;0,0,0,1;False;5;FLOAT4;0;FLOAT;1;FLOAT;2;FLOAT;3;FLOAT;4
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;49;851.5135,1250.798;Inherit;False;2;2;0;FLOAT;0;False;1;FLOAT4;0,0,0,0;False;1;FLOAT4;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;55;834.9081,1760.015;Inherit;False;2;2;0;FLOAT;0;False;1;FLOAT3;0,0,0;False;1;FLOAT3;0
Node;AmplifyShaderEditor.SimpleAddOpNode;39;-452.6598,372.8075;Inherit;False;2;2;0;FLOAT3;0,0,0;False;1;FLOAT3;0,0,0;False;1;FLOAT3;0
Node;AmplifyShaderEditor.SimpleMultiplyOpNode;63;1447.641,76.28424;Inherit;False;2;2;0;FLOAT;0;False;1;COLOR;0,0,0,0;False;1;COLOR;0
Node;AmplifyShaderEditor.SimpleAddOpNode;58;1022.619,1248.882;Inherit;False;2;2;0;FLOAT4;0,0,0,0;False;1;FLOAT3;0,0,0;False;1;FLOAT4;0
Node;AmplifyShaderEditor.SimpleAddOpNode;56;674.9652,1766.029;Inherit;False;2;2;0;FLOAT3;0,0,0;False;1;FLOAT3;0,0,0;False;1;FLOAT3;0
Node;AmplifyShaderEditor.NormalizeNode;48;670.6122,1357.898;Inherit;False;1;0;FLOAT4;0,0,0,0;False;1;FLOAT4;0
Node;AmplifyShaderEditor.StandardSurfaceOutputNode;0;1640.644,118.9729;Float;False;True;-1;2;ASEMaterialInspector;0;0;Standard;Toon Fire;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;False;Back;0;False;-1;0;False;-1;False;0;False;-1;0;False;-1;False;0;Custom;0.5;True;True;0;True;TransparentCutout;;Geometry;All;14;all;True;True;True;True;0;False;-1;False;0;False;-1;255;False;-1;255;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;-1;False;2;15;10;25;False;0.5;True;0;0;False;-1;0;False;-1;0;0;False;-1;0;False;-1;0;False;-1;0;False;-1;0;False;0;0,0,0,0;VertexOffset;True;False;Spherical;False;Relative;0;;0;-1;-1;-1;0;False;0;0;False;-1;-1;0;False;-1;0;0;0;False;0.1;False;-1;0;False;-1;False;16;0;FLOAT3;0,0,0;False;1;FLOAT3;0,0,0;False;2;FLOAT3;0,0,0;False;3;FLOAT;0;False;4;FLOAT;0;False;5;FLOAT;0;False;6;FLOAT3;0,0,0;False;7;FLOAT3;0,0,0;False;8;FLOAT;0;False;9;FLOAT;0;False;10;FLOAT;0;False;13;FLOAT3;0,0,0;False;11;FLOAT3;0,0,0;False;12;FLOAT3;0,0,0;False;14;FLOAT4;0,0,0,0;False;15;FLOAT3;0,0,0;False;0
WireConnection;8;0;14;0
WireConnection;8;1;16;0
WireConnection;9;1;12;0
WireConnection;17;1;13;0
WireConnection;18;0;16;0
WireConnection;18;1;15;0
WireConnection;11;0;18;0
WireConnection;11;2;17;0
WireConnection;10;0;8;0
WireConnection;10;2;9;0
WireConnection;5;0;3;0
WireConnection;5;1;10;0
WireConnection;6;0;3;0
WireConnection;6;1;11;0
WireConnection;7;0;5;0
WireConnection;7;1;6;0
WireConnection;19;0;7;0
WireConnection;19;1;20;0
WireConnection;68;0;69;2
WireConnection;68;2;67;0
WireConnection;35;0;19;0
WireConnection;70;0;68;0
WireConnection;33;0;35;0
WireConnection;71;0;68;0
WireConnection;71;1;66;0
WireConnection;23;0;31;0
WireConnection;23;1;33;0
WireConnection;24;0;32;0
WireConnection;24;1;33;0
WireConnection;73;0;28;0
WireConnection;73;1;70;0
WireConnection;34;0;23;0
WireConnection;34;1;24;0
WireConnection;72;0;73;0
WireConnection;72;1;71;0
WireConnection;37;0;34;0
WireConnection;37;1;72;0
WireConnection;36;0;24;0
WireConnection;36;1;27;0
WireConnection;38;0;36;0
WireConnection;38;1;37;0
WireConnection;46;0;47;0
WireConnection;46;1;45;0
WireConnection;49;0;50;0
WireConnection;49;1;48;0
WireConnection;55;0;54;0
WireConnection;55;1;56;0
WireConnection;39;0;34;0
WireConnection;39;1;24;0
WireConnection;63;0;64;0
WireConnection;63;1;38;0
WireConnection;58;0;49;0
WireConnection;58;1;55;0
WireConnection;56;0;52;0
WireConnection;56;1;53;0
WireConnection;48;0;46;0
WireConnection;0;2;63;0
WireConnection;0;10;39;0
ASEEND*/
//CHKSM=C6AA0EB8E5B098DEC3BE0D78C2ADD85AE73E779A