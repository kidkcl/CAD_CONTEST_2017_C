module patch (w707, n588);
input n588;
output w707;
wire w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16, w17, w18, w19, w20, w21, w22, w23, w24, w25, w26, w27, w28, w29, w30, w31, w32, w33, w34, w35, w36, w37, w38, w39, w40, w41, w42, w43, w44, w45, w46, w47, w48, w49, w50, w51, w52, w53, w54, w55, w56, w57, w58, w59, w60, w61, w62, w63, w64, w65, w66, w67, w68, w69, w70, w71, w72, w73, w74, w75, w76, w77, w78, w79, w80, w81, w82, w83, w84, w85, w86, w87, w88, w89, w90, w91, w92, w93, w94, w95, w96, w97, w98, w99, w100, w101, w102, w103, w104, w105, w106, w107, w108, w109, w110, w111, w112, w113, w114, w115, w116, w117, w118, w119, w120, w121, w122, w123, w124, w125, w126, w127, w128, w129, w130, w131, w132, w133, w134, w135, w136, w137, w138, w139, w140, w141, w142, w143, w144, w145, w146, w147, w148, w149, w150, w151, w152, w153, w154, w155, w156, w157, w158, w159, w160, w161, w162, w163, w164, w165, w166, w167, w168, w169, w170, w171, w172, w173, w174, w175, w176, w177, w178, w179, w180, w181, w182, w183, w184, w185, w186, w187, w188, w189, w190, w191, w192, w193, w194, w195, w196, w197, w198, w199, w200, w201, w202, w203, w204, w205, w206, w207, w208, w209, w210, w211, w212, w213, w214, w215, w216, w217, w218, w219, w220, w221, w222, w223, w224, w225, w226, w227, w228, w229, w230, w231, w232, w233, w234, w235, w236, w237, w238, w239, w240, w241, w242, w243, w244, w245, w246, w247, w248, w249, w250, w251, w252, w253, w254, w255, w256, w257, w258, w259, w260, w261, w262, w263, w264, w265, w266, w267, w268, w269, w270, w271, w272, w273, w274, w275, w276, w277, w278, w279, w280, w281, w282, w283, w284, w285, w286, w287, w288, w289, w290, w291, w292, w293, w294, w295, w296, w297, w298, w299, w300, w301, w302, w303, w304, w305, w306, w307, w308, w309, w310, w311, w312, w313, w314, w315, w316, w317, w318, w319, w320, w321, w322, w323, w324, w325, w326, w327, w328, w329, w330, w331, w332, w333, w334, w335, w336, w337, w338, w339, w340, w341, w342, w343, w344, w345, w346, w347, w348, w349, w350, w351, w352, w353, w354, w355, w356, w357, w358, w359, w360, w361, w362, w363, w364, w365, w366, w367, w368, w369, w370, w371, w372, w373, w374, w375, w376, w377, w378, w379, w380, w381, w382, w383, w384, w385, w386, w387, w388, w389, w390, w391, w392, w393, w394, w395, w396, w397, w398, w399, w400, w401, w402, w403, w404, w405, w406, w407, w408, w409, w410, w411, w412, w413, w414, w415, w416, w417, w418, w419, w420, w421, w422, w423, w424, w425, w426, w427, w428, w429, w430, w431, w432, w433, w434, w435, w436, w437, w438, w439, w440, w441, w442, w443, w444, w445, w446, w447, w448, w449, w450, w451, w452, w453, w454, w455, w456, w457, w458, w459, w460, w461, w462, w463, w464, w465, w466, w467, w468, w469, w470, w471, w472, w473, w474, w475, w476, w477, w478, w479, w480, w481, w482, w483, w484, w485, w486, w487, w488, w489, w490, w491, w492, w493, w494, w495, w496, w497, w498, w499, w500, w501, w502, w503, w504, w505, w506, w507, w508, w509, w510, w511, w512, w513, w514, w515, w516, w517, w518, w519, w520, w521, w522, w523, w524, w525, w526, w527, w528, w529, w530, w531, w532, w533, w534, w535, w536, w537, w538, w539, w540, w541, w542, w543, w544, w545, w546, w547, w548, w549, w550, w551, w552, w553, w554, w555, w556, w557, w558, w559, w560, w561, w562, w563, w564, w565, w566, w567, w568, w569, w570, w571, w572, w573, w574, w575, w576, w577, w578, w579, w580, w581, w582, w583, w584, w585, w586, w587, w588, w589, w590, w591, w592, w593, w594, w595, w596, w597, w598, w599, w600, w601, w602, w603, w604, w605, w606, w607, w608, w609, w610, w611, w612, w613, w614, w615, w616, w617, w618, w619, w620, w621, w622, w623, w624, w625, w626, w627, w628, w629, w630, w631, w632, w633, w634, w635, w636, w637, w638, w639, w640, w641, w642, w643, w644, w645, w646, w647, w648, w649, w650, w651, w652, w653, w654, w655, w656, w657, w658, w659, w660, w661, w662, w663, w664, w665, w666, w667, w668, w669, w670, w671, w672, w673, w674, w675, w676, w677, w678, w679, w680, w681, w682, w683, w684, w685, w686, w687, w688, w689, w690, w691, w692, w693, w694, w695, w696, w697, w698, w699, w700, w701, w702, w703, w704, w705, w706, w707;
not(w0, n588);
not(w1, n588);
not(w2, n588);
and (w3, w1, n588);
and (w4, w2, n588);
or (w5, w3, w2);
or (w6, w5, w1);
or (w7, w6, w2);
or (w8, w7, w2);
or (w9, w3, w2);
or (w10, w9, w8);
or (w11, w10, w3);
or (w12, w11, w2);
or (w13, w12, w2);
or (w14, w13, w0);
or (w15, w14, w4);
or (w16, w15, w1);
or (w17, w16, w2);
or (w18, w0, w4);
or (w19, w18, w1);
or (w20, w19, w2);
or (w21, w20, w0);
or (w22, w21, w4);
or (w23, w22, w1);
or (w24, w23, w2);
or (w25, w24, w17);
or (w26, w1, w0);
or (w27, w1, w26);
or (w28, w27, w2);
or (w29, w28, w1);
or (w30, w13, w0);
or (w31, w30, w1);
or (w32, w31, w2);
or (w33, w1, w0);
or (w34, w33, w1);
or (w35, w29, w1);
or (w36, w1, w33);
or (w37, w36, w1);
or (w38, w34, w1);
or (w39, w38, w37);
or (w40, w39, w35);
or (w41, w40, w1);
or (w42, w1, w41);
or (w43, w42, w1);
or (w44, w33, w1);
or (w45, w44, w1);
or (w46, w45, w1);
or (w47, w34, w1);
or (w48, w47, w1);
or (w49, w48, w46);
or (w50, w49, w1);
or (w51, w50, w46);
or (w52, w51, w1);
or (w53, w13, w1);
or (w54, w53, w2);
or (w55, w54, w13);
or (w56, w55, w0);
or (w57, w56, w1);
or (w58, w57, w2);
or (w59, w54, w13);
or (w60, w59, w2);
or (w61, w25, w60);
or (w62, w61, w0);
or (w63, w62, w4);
or (w64, w63, w1);
or (w65, w64, w52);
or (w66, w65, w2);
or (w67, w32, w25);
or (w68, w67, w60);
or (w69, w68, w0);
or (w70, w69, w4);
or (w71, w70, w1);
or (w72, w71, w52);
or (w73, w72, w2);
or (w74, w60, w1);
or (w75, w74, w2);
or (w76, w0, w1);
or (w77, w32, w0);
or (w78, w77, w1);
or (w79, w78, w76);
or (w80, w79, w2);
or (w81, w1, w2);
or (w82, w81, w1);
or (w83, w32, w0);
or (w84, w83, w1);
or (w85, w84, w75);
or (w86, w85, w2);
or (w87, w3, w2);
or (w88, w87, w3);
or (w89, w88, w2);
or (w90, w89, w2);
or (w91, w4, w1);
or (w92, w91, w1);
or (w93, w2, w76);
or (w94, w93, w2);
or (w95, w2, w76);
or (w96, w95, w94);
or (w97, w96, w2);
or (w98, w2, w97);
or (w99, w76, w2);
or (w100, w99, w98);
or (w101, w100, w97);
or (w102, w76, w101);
or (w103, w102, w101);
or (w104, w103, w92);
or (w105, w104, w1);
or (w106, w76, w4);
or (w107, w106, w1);
or (w108, w107, w2);
or (w109, w108, w1);
or (w110, w73, w66);
or (w111, w110, w43);
or (w112, w111, w2);
or (w113, w58, w73);
or (w114, w113, w112);
or (w115, w114, w52);
or (w116, w115, w2);
or (w117, w86, w75);
or (w118, w117, w116);
or (w119, w82, w118);
or (w120, w119, w116);
or (w121, w13, w97);
or (w122, w121, w105);
or (w123, w122, w80);
or (w124, w1, w123);
or (w125, w124, w120);
or (w126, w125, w116);
or (w127, w126, w2);
or (w128, w60, w1);
or (w129, w60, w97);
or (w130, w129, w105);
or (w131, w1, w130);
or (w132, w131, w128);
or (w133, w132, w2);
or (w134, w80, w133);
or (w135, w134, w120);
or (w136, w135, w116);
or (w137, w92, w136);
or (w138, w136, w137);
or (w139, w138, w136);
or (w140, w13, w1);
or (w141, w140, w1);
or (w142, w141, w2);
or (w143, w142, w0);
or (w144, w143, w1);
or (w145, w144, w2);
or (w146, w1, w145);
or (w147, w146, w1);
or (w148, w147, w2);
or (w149, w142, w148);
or (w150, w149, w0);
or (w151, w150, w1);
or (w152, w151, w2);
or (w153, w1, w152);
or (w154, w153, w148);
or (w155, w154, w1);
or (w156, w155, w2);
or (w157, w76, w142);
or (w158, w157, w0);
or (w159, w158, w97);
or (w160, w159, w105);
or (w161, w160, w156);
or (w162, w1, w161);
or (w163, w162, w156);
or (w164, w163, w2);
or (w165, w105, w164);
or (w166, w92, w127);
or (w167, w166, w137);
or (w168, w167, w165);
or (w169, w136, w127);
or (w170, w169, w165);
or (w171, w139, w170);
or (w172, w171, w168);
or (w173, w172, w165);
or (w174, w173, w170);
or (w175, w174, w168);
or (w176, w175, w165);
or (w177, w136, w176);
or (w178, w177, w173);
or (w179, w178, w170);
or (w180, w179, w168);
or (w181, w180, w165);
or (w182, w1, w181);
or (w183, w1, w182);
or (w184, w183, w181);
or (w185, w3, w2);
or (w186, w185, w1);
or (w187, w186, w2);
or (w188, w187, w181);
or (w189, w188, w184);
or (w190, w189, w0);
or (w191, w190, w1);
or (w192, w191, w2);
or (w193, w188, w192);
or (w194, w193, w2);
or (w195, w0, w1);
or (w196, w195, w181);
or (w197, w1, w196);
or (w198, w197, w194);
or (w199, w198, w1);
or (w200, w199, w2);
or (w201, w200, w181);
or (w202, w188, w201);
or (w203, w202, w0);
or (w204, w203, w1);
or (w205, w204, w2);
or (w206, w1, w182);
or (w207, w206, w205);
or (w208, w207, w201);
or (w209, w208, w1);
or (w210, w209, w2);
or (w211, w210, w181);
or (w212, w0, w1);
or (w213, w212, w181);
or (w214, w213, w211);
or (w215, w214, w201);
or (w216, w215, w1);
or (w217, w216, w2);
or (w218, w217, w181);
or (w219, w105, w181);
or (w220, w219, w218);
or (w221, w220, w181);
or (w222, w219, w188);
or (w223, w222, w103);
or (w224, w223, w0);
or (w225, w224, w105);
or (w226, w225, w221);
or (w227, w226, w181);
or (w228, w219, w221);
or (w229, w76, w188);
or (w230, w229, w228);
or (w231, w230, w103);
or (w232, w231, w227);
or (w233, w232, w0);
or (w234, w233, w105);
or (w235, w234, w221);
or (w236, w235, w181);
or (w237, w1, w236);
or (w238, w237, w221);
or (w239, w238, w181);
or (w240, w221, w181);
or (w241, w240, w2);
or (w242, w241, w239);
or (w243, w242, w236);
or (w244, w243, w221);
or (w245, w244, w181);
or (w246, w219, w2);
or (w247, w246, w0);
or (w248, w247, w103);
or (w249, w248, w105);
or (w250, w249, w245);
or (w251, w250, w221);
or (w252, w251, w181);
or (w253, w1, w245);
or (w254, w253, w181);
or (w255, w2, w254);
or (w256, w255, w252);
or (w257, w256, w245);
or (w258, w257, w221);
or (w259, w258, w181);
or (w260, w76, w2);
or (w261, w260, w0);
or (w262, w261, w103);
or (w263, w262, w105);
or (w264, w263, w228);
or (w265, w264, w259);
or (w266, w265, w245);
or (w267, w266, w221);
or (w268, w267, w181);
or (w269, w2, w254);
or (w270, w269, w268);
or (w271, w270, w259);
or (w272, w271, w245);
or (w273, w272, w221);
or (w274, w273, w181);
or (w275, w274, w3);
or (w276, w275, w274);
or (w277, w276, w2);
or (w278, w277, w3);
or (w279, w278, w274);
or (w280, w279, w2);
or (w281, w280, w274);
or (w282, w281, w274);
or (w283, w282, w274);
or (w284, w274, w283);
or (w285, w284, w274);
or (w286, w285, w274);
or (w287, w286, w2);
or (w288, w90, w274);
or (w289, w288, w274);
or (w290, w274, w289);
or (w291, w290, w274);
or (w292, w291, w274);
or (w293, w292, w274);
or (w294, w293, w274);
or (w295, w294, w274);
or (w296, w295, w274);
or (w297, w296, w287);
or (w298, w297, w2);
or (w299, w274, w1);
or (w300, w299, w274);
or (w301, w300, w274);
or (w302, w301, w274);
or (w303, w302, w274);
or (w304, w303, w274);
or (w305, w304, w274);
or (w306, w305, w274);
or (w307, w306, w274);
or (w308, w307, w274);
or (w309, w308, w274);
or (w310, w309, w274);
or (w311, w310, w274);
or (w312, w274, w311);
or (w313, w312, w1);
or (w314, w313, w274);
or (w315, w314, w274);
or (w316, w315, w274);
or (w317, w316, w274);
or (w318, w317, w274);
or (w319, w318, w274);
or (w320, w319, w274);
or (w321, w320, w274);
or (w322, w321, w274);
or (w323, w322, w274);
or (w324, w323, w274);
or (w325, w324, w274);
or (w326, w325, w274);
or (w327, w326, w274);
or (w328, w274, w327);
or (w329, w328, w1);
or (w330, w329, w274);
or (w331, w330, w274);
or (w332, w331, w274);
or (w333, w332, w274);
or (w334, w333, w274);
or (w335, w334, w274);
or (w336, w335, w274);
or (w337, w336, w274);
or (w338, w337, w274);
or (w339, w338, w274);
or (w340, w339, w274);
or (w341, w340, w274);
or (w342, w341, w274);
or (w343, w298, w274);
or (w344, w343, w4);
or (w345, w344, w1);
or (w346, w345, w2);
or (w347, w274, w1);
or (w348, w347, w327);
or (w349, w348, w274);
or (w350, w349, w274);
or (w351, w350, w274);
or (w352, w351, w274);
or (w353, w352, w274);
or (w354, w353, w274);
or (w355, w354, w274);
or (w356, w355, w342);
or (w357, w356, w274);
or (w358, w357, w274);
or (w359, w358, w274);
or (w360, w359, w346);
or (w361, w360, w274);
or (w362, w361, w274);
or (w363, w362, w274);
or (w364, w363, w274);
or (w365, w364, w274);
or (w366, w365, w274);
or (w367, w366, w274);
or (w368, w367, w274);
or (w369, w368, w274);
or (w370, w369, w274);
or (w371, w298, w274);
or (w372, w371, w109);
or (w373, w372, w2);
or (w374, w373, w274);
or (w375, w374, w274);
or (w376, w76, w298);
or (w377, w376, w274);
or (w378, w377, w109);
or (w379, w378, w2);
or (w380, w379, w274);
or (w381, w380, w274);
or (w382, w381, w375);
or (w383, w274, w1);
or (w384, w383, w274);
or (w385, w384, w274);
or (w386, w385, w274);
or (w387, w386, w274);
or (w388, w387, w274);
or (w389, w388, w274);
or (w390, w389, w274);
or (w391, w390, w274);
or (w392, w391, w274);
or (w393, w392, w274);
or (w394, w393, w274);
or (w395, w394, w274);
or (w396, w395, w274);
or (w397, w396, w274);
or (w398, w397, w274);
or (w399, w398, w274);
or (w400, w399, w274);
or (w401, w274, w76);
or (w402, w401, w274);
or (w403, w402, w1);
or (w404, w403, w274);
or (w405, w404, w274);
or (w406, w405, w274);
or (w407, w406, w274);
or (w408, w407, w274);
or (w409, w408, w274);
or (w410, w409, w274);
or (w411, w410, w274);
or (w412, w411, w274);
or (w413, w412, w400);
or (w414, w413, w382);
or (w415, w414, w370);
or (w416, w415, w274);
or (w417, w416, w274);
or (w418, w417, w274);
or (w419, w418, w274);
or (w420, w419, w274);
or (w421, w420, w274);
or (w422, w421, w274);
or (w423, w422, w274);
or (w424, w423, w274);
or (w425, w274, w346);
or (w426, w425, w382);
or (w427, w274, w1);
or (w428, w427, w274);
or (w429, w428, w274);
or (w430, w429, w274);
or (w431, w430, w274);
or (w432, w431, w274);
or (w433, w432, w274);
or (w434, w433, w274);
or (w435, w434, w274);
or (w436, w435, w274);
or (w437, w436, w274);
or (w438, w437, w274);
or (w439, w274, w402);
or (w440, w439, w1);
or (w441, w440, w274);
or (w442, w441, w274);
or (w443, w442, w274);
or (w444, w443, w274);
or (w445, w444, w274);
or (w446, w445, w274);
or (w447, w446, w274);
or (w448, w447, w274);
or (w449, w448, w274);
or (w450, w449, w274);
or (w451, w450, w438);
or (w452, w451, w426);
or (w453, w452, w274);
or (w454, w453, w274);
or (w455, w454, w274);
or (w456, w455, w274);
or (w457, w456, w274);
or (w458, w457, w274);
or (w459, w458, w274);
or (w460, w459, w424);
or (w461, w1, w274);
or (w462, w461, w1);
or (w463, w462, w274);
or (w464, w463, w274);
or (w465, w464, w1);
or (w466, w465, w274);
or (w467, w466, w274);
or (w468, w467, w274);
or (w469, w468, w274);
or (w470, w469, w274);
or (w471, w470, w1);
or (w472, w471, w460);
or (w473, w1, w274);
or (w474, w473, w1);
or (w475, w474, w274);
or (w476, w475, w274);
or (w477, w476, w274);
or (w478, w477, w274);
or (w479, w478, w1);
or (w480, w479, w460);
or (w481, w274, w480);
or (w482, w481, w1);
or (w483, w482, w274);
or (w484, w483, w274);
or (w485, w484, w274);
or (w486, w485, w274);
or (w487, w486, w472);
or (w488, w487, w274);
or (w489, w488, w274);
or (w490, w489, w274);
or (w491, w490, w274);
or (w492, w491, w274);
or (w493, w492, w1);
or (w494, w493, w460);
or (w495, w274, w1);
or (w496, w495, w480);
or (w497, w496, w1);
or (w498, w497, w274);
or (w499, w498, w274);
or (w500, w499, w274);
or (w501, w500, w274);
or (w502, w501, w1);
or (w503, w502, w460);
or (w504, w274, w1);
or (w505, w504, w274);
or (w506, w505, w274);
or (w507, w506, w503);
or (w508, w507, w274);
or (w509, w508, w274);
or (w510, w509, w274);
or (w511, w510, w274);
or (w512, w511, w1);
or (w513, w512, w460);
or (w514, w472, w513);
or (w515, w514, w274);
or (w516, w515, w274);
or (w517, w516, w494);
or (w518, w517, w274);
or (w519, w518, w274);
or (w520, w519, w274);
or (w521, w520, w1);
or (w522, w521, w460);
or (w523, w426, w0);
or (w524, w523, w1);
or (w525, w524, w2);
or (w526, w525, w274);
or (w527, w522, w274);
or (w528, w527, w526);
or (w529, w528, w2);
or (w530, w529, w274);
or (w531, w0, w109);
or (w532, w531, w426);
or (w533, w532, w530);
or (w534, w533, w2);
or (w535, w534, w274);
or (w536, w274, w503);
or (w537, w536, w274);
or (w538, w537, w1);
or (w539, w538, w274);
or (w540, w539, w274);
or (w541, w540, w274);
or (w542, w541, w274);
or (w543, w542, w274);
or (w544, w543, w274);
or (w545, w544, w274);
or (w546, w545, w274);
or (w547, w546, w274);
or (w548, w547, w1);
or (w549, w480, w274);
or (w550, w549, w1);
or (w551, w550, w274);
or (w552, w551, w274);
or (w553, w552, w274);
or (w554, w553, w274);
or (w555, w554, w548);
or (w556, w555, w274);
or (w557, w556, w274);
or (w558, w557, w274);
or (w559, w558, w1);
or (w560, w480, w274);
or (w561, w560, w1);
or (w562, w561, w274);
or (w563, w562, w274);
or (w564, w563, w274);
or (w565, w564, w274);
or (w566, w565, w513);
or (w567, w566, w274);
or (w568, w567, w274);
or (w569, w568, w274);
or (w570, w569, w559);
or (w571, w570, w274);
or (w572, w571, w274);
or (w573, w572, w1);
or (w574, w573, w535);
or (w575, w574, w530);
or (w576, w575, w2);
or (w577, w576, w274);
or (w578, w76, w0);
or (w579, w578, w109);
or (w580, w579, w426);
or (w581, w580, w577);
or (w582, w581, w530);
or (w583, w582, w2);
or (w584, w583, w274);
or (w585, w480, w274);
or (w586, w585, w1);
or (w587, w586, w274);
or (w588, w587, w274);
or (w589, w588, w274);
or (w590, w589, w274);
or (w591, w590, w513);
or (w592, w591, w274);
or (w593, w592, w274);
or (w594, w593, w274);
or (w595, w594, w559);
or (w596, w595, w274);
or (w597, w596, w274);
or (w598, w597, w1);
or (w599, w598, w584);
or (w600, w599, w577);
or (w601, w600, w530);
or (w602, w601, w2);
or (w603, w602, w274);
or (w604, w274, w1);
or (w605, w604, w327);
or (w606, w605, w274);
or (w607, w606, w274);
or (w608, w607, w274);
or (w609, w608, w274);
or (w610, w609, w274);
or (w611, w610, w274);
or (w612, w611, w274);
or (w613, w612, w274);
or (w614, w613, w274);
or (w615, w614, w274);
or (w616, w615, w274);
or (w617, w616, w274);
or (w618, w617, w274);
or (w619, w618, w274);
or (w620, w619, w274);
or (w621, w620, w342);
or (w622, w621, w438);
or (w623, w622, w603);
or (w624, w274, w603);
or (w625, w274, w624);
or (w626, w625, w274);
or (w627, w626, w603);
or (w628, w0, w1);
or (w629, w628, w627);
or (w630, w629, w623);
or (w631, w630, w460);
or (w632, w274, w402);
or (w633, w632, w274);
or (w634, w633, w274);
or (w635, w634, w274);
or (w636, w635, w274);
or (w637, w636, w274);
or (w638, w637, w274);
or (w639, w638, w274);
or (w640, w639, w274);
or (w641, w640, w274);
or (w642, w641, w274);
or (w643, w642, w274);
or (w644, w643, w603);
or (w645, w402, w274);
or (w646, w645, w274);
or (w647, w646, w274);
or (w648, w647, w274);
or (w649, w648, w274);
or (w650, w649, w274);
or (w651, w650, w274);
or (w652, w651, w274);
or (w653, w652, w274);
or (w654, w653, w274);
or (w655, w654, w274);
or (w656, w655, w274);
or (w657, w656, w274);
or (w658, w657, w274);
or (w659, w658, w644);
or (w660, w659, w603);
or (w661, w0, w1);
or (w662, w661, w660);
or (w663, w662, w76);
or (w664, w663, w631);
or (w665, w664, w623);
or (w666, w665, w460);
or (w667, w274, w666);
or (w668, w667, w603);
or (w669, w274, w668);
or (w670, w669, w274);
or (w671, w670, w666);
or (w672, w671, w603);
or (w673, w274, w672);
or (w674, w673, w274);
or (w675, w674, w666);
or (w676, w675, w603);
or (w677, w274, w676);
or (w678, w677, w672);
or (w679, w678, w274);
or (w680, w679, w666);
or (w681, w680, w603);
or (w682, w274, w681);
or (w683, w682, w666);
or (w684, w683, w603);
or (w685, w274, w684);
or (w686, w685, w274);
or (w687, w686, w681);
or (w688, w687, w666);
or (w689, w688, w603);
or (w690, w627, w689);
or (w691, w690, w681);
or (w692, w691, w666);
or (w693, w692, w603);
or (w694, w274, w693);
or (w695, w694, w689);
or (w696, w695, w681);
or (w697, w696, w666);
or (w698, w697, w603);
or (w699, w274, w698);
or (w700, w699, w693);
or (w701, w700, w689);
or (w702, w701, w681);
or (w703, w702, w666);
or (w704, w703, w603);
or (w705, w704, w274);
or (w706, w704, w274);
or (w707, w705, w706);
endmodule