
echo(version=version());

$fn = 100;


ext_cover_circ_r = 136.5/2;
int_cover_circ_r = 130.5/2;
cover_height = 2.4;
edge_height = 8;

sensor_circ_r = 8.25;
sensor_holes_spacing = 9.55;

aux_holes_r = 21;

module aux_holes() {
    union() {
      translate([aux_holes_r + 12, aux_holes_r + 5, -cover_height]) cylinder(h = cover_height*2, r = aux_holes_r);
      translate([-(aux_holes_r + 12), -(aux_holes_r + 5), -cover_height]) cylinder(h = cover_height*2, r = aux_holes_r);
      translate([aux_holes_r + 12, -(aux_holes_r + 5), -cover_height]) cylinder(h = cover_height*2, r = aux_holes_r);
      translate([-(aux_holes_r + 12), aux_holes_r + 5, -cover_height]) cylinder(h = cover_height*2, r = aux_holes_r);
   }   
}

module sensor_holes() {
   union() {
       translate([0, (sensor_circ_r + sensor_holes_spacing/2), -cover_height]) cylinder(h = cover_height*2, r = sensor_circ_r);
       translate([0, -(sensor_circ_r + sensor_holes_spacing/2), -cover_height]) cylinder(h = cover_height*2, r = sensor_circ_r);
   }
}

module edge_ring(){
   difference() {
       cylinder(h = edge_height, r = ext_cover_circ_r, center = true);
       cylinder(h = edge_height, r = int_cover_circ_r, center = true);
   }
}

module tank_cover(){
    difference() {
        union() {
            cylinder(h = cover_height, r = ext_cover_circ_r, center = true);
            translate([0, 0, cover_height]) edge_ring();
        }
        sensor_holes();
        aux_holes();
    }
}


//translate([-(circunference_r + 5), 0, 0])
//projection(cut = true) tank_cover();
tank_cover();